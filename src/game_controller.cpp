#include "logger.h"
#include "game_controller.h"
#include <random>
#include <functional>

/**
 * Constructor default.
 *
 * Initializes all objects for this game
 *
 */
GameController::GameController()
{
    // Creates the window
    _window = std::make_unique<Window>();
    // Set up all the objects to use SDL
    _isGameInitialized = _window->Initialize();

    // Checks if all is loaded correctly
    if (_isGameInitialized)
    {
        // Set the state as a menu
        _currentGameState = Game_State::MENU;
        // Load the best score
        LoadBestScore();
        // Spawn the players (paddle and ball)
        SpawnPlayers();
        // Spawn the blocks
        SpawnBlocks();
        // Initializes the music
        InitializeSound();
    }
}

GameController::~GameController()
{
}

/**
 * Run the game loop.
 *
 * if all is loaded the game loop starts.
 *
 */
void GameController::Run()
{
    if (!_isGameInitialized)
        Logger::LogLibraryError("Game::Run() ", "Game cannot be initialized");
    else
    {
        Uint32 startTicks = 0;
        Uint32 endTicks = 0;

        while (_window->GetCurrentWindowState() == Window_State::WINDOW_RUNNING)
        {
            startTicks = SDL_GetTicks();

            // Event
            ProcessInput();

            // Physics
            Update();
            CheckCollisions();

            // Render
            _window->ClearRender();
            Render();
            _window->UpdateRender();

            endTicks = SDL_GetTicks() - startTicks;

            if (endTicks < DELAY)
                SDL_Delay((int)(DELAY - endTicks));
        }
        Clear();
    }
}

/**
 * Process the input.
 *
 * processes if any key of interest is pressed and sends it to the objects that require it.
 *
 */
void GameController::ProcessInput()
{
    int input = _window->Input();
    if (_currentGameState == Game_State::PLAYING)
    {
        _paddlePlayer->SendInput(input);
        _paddleEnemy->SendInput(Utilities::BrainPaddleInputValue(_paddleEnemy->GetBoxCollision(), _ballEnemy->GetBoxCollision()));
    }
    if (_currentGameState != Game_State::PLAYING && input > 0)
    {
        if (_currentGameState == Game_State::GAME_OVER)
            ResetGame();
        _currentGameState = Game_State::PLAYING;
    }
}

/**
 * Update the game loop.
 *
 * Calls the Update to the required objects.
 *
 */
void GameController::Update()
{
    SetMenuText();
    if (_currentGameState == Game_State::PLAYING)
    {
        _ballPlayer->Update();
        _ballEnemy->Update();
        _paddlePlayer->Update();
        _paddleEnemy->Update();
    }
}

/**
 * Render the game loop.
 *
 * Calls the Render to the required objects.
 *
 */
void GameController::Render()
{
    _background->Draw(_window->GetRenderer());
    if (_currentGameState == Game_State::PLAYING)
    {
        _ballPlayer->Draw(_window->GetRenderer());
        _ballEnemy->Draw(_window->GetRenderer());
        _paddlePlayer->Draw(_window->GetRenderer());
        _paddleEnemy->Draw(_window->GetRenderer());

        for (auto block : _blocks)
            block->Draw(_window->GetRenderer());
    }

    _uiDisplay->Draw(_window->GetRenderer(), _uiDisplay->GetText(), _uiDisplay->GetColor());
}

/**
 * Clear the objects.
 *
 * Calls the Clear when objects are no longer needed.
 *
 */
void GameController::Clear()
{
    _ballPlayer->Clean();
    _ballEnemy->Clean();
    _paddlePlayer->Clean();
    _paddleEnemy->Clean();
    _uiDisplay->Clean();
    _soundHandler->Clean();
}

/**
 * Spawn randomly the blocks for the game.
 */
void GameController::SpawnBlocks()
{
    float offset = 30;
    float startW = _window->GetScreenWidth() / 3;
    float startH = offset;

    float segmentsW = startW / 15;
    float segmentsH = (_window->GetScreenHeight() - offset) / 20;

    std::random_device randomDevice;
    std::mt19937 generator(randomDevice());
    std::uniform_int_distribution<int> distribution(0, 100);
    auto getRandom = std::bind(distribution, generator);

    for (int row = 1; row <= segmentsW; row++)
    {
        startH = offset;
        for (int col = 1; col <= segmentsH; col++)
        {
            if (getRandom() < 50)
            {
                _blocks.emplace_back(new Block({startW, startH}, "Block" + std::to_string(row) + std::to_string(col)));
            }
            startH += 20;
            Logger::LogLibrary("SPAWN BLOCKS row: ", std::to_string(startW * row) + " col: " + std::to_string(startW * row));
        }
        startW += 15;
    }
}
/**
 * Spawn the player and the bot.
 */
void GameController::SpawnPlayers()
{
    float propWidth = _window->GetScreenWidth() / 4;
    float propHeight = _window->GetScreenHeight() / 2;
    
    _ballPlayer = std::unique_ptr<Ball>(new Ball("../resources/ball.png", {propWidth, propHeight}, {0, 0}, {propWidth * 3, static_cast<float>(_window->GetScreenHeight())}));
    _ballPlayer->Initialize(_window->GetRenderer(), _window->GetSurface());
    _ballPlayer->SetTag("BallPlayer");

    _ballEnemy = std::unique_ptr<Ball>(new Ball("../resources/enemy-ball.png", {propWidth * 3, propHeight}, {propWidth, 0}, {static_cast<float>(_window->GetScreenWidth()), static_cast<float>(_window->GetScreenHeight())}));
    _ballEnemy->Initialize(_window->GetRenderer(), _window->GetSurface());
    _ballEnemy->SetTag("BallEnemy");

    _paddlePlayer = std::unique_ptr<Paddle>(new Paddle("../resources/paddle.png", {10, propHeight}, {0, static_cast<float>(_window->GetScreenHeight())}));
    _paddlePlayer->Initialize(_window->GetRenderer(), _window->GetSurface());
    _paddlePlayer->SetTag("PaddlePlayer");

    _paddleEnemy = std::unique_ptr<Paddle>(new Paddle("../resources/paddle1.png", {static_cast<float>(_window->GetScreenWidth() - 50), propHeight}, {0, static_cast<float>(_window->GetScreenHeight())}));
    _paddleEnemy->Initialize(_window->GetRenderer(), _window->GetSurface());
    _paddleEnemy->SetTag("PaddleEnemy");

    _uiDisplay = std::unique_ptr<UIDisplay>(new UIDisplay("../resources/Acme-Regular.ttf", {propWidth, 0}, {propWidth * 2, 45}));
    _uiDisplay->Initialize(_uiDisplay->GetText(), _window->GetRenderer(), _window->GetSurface(), _uiDisplay->GetColor());
    
    _background = std::unique_ptr<Background>(new Background("../resources/Background_space.png", {0, 0}, {propWidth * 4, propHeight * 2}));
    _background->Initialize(_window->GetRenderer(), _window->GetSurface());
    _background->SetTag("Background");
}

/**
 * Check the collisions for game loop.
 */
void GameController::CheckCollisions()
{
    if (Utilities::CheckCollision(_ballPlayer->GetBoxCollision(), _paddlePlayer->GetBoxCollision()))
    {
        _ballPlayer->CollisionDetected(_paddlePlayer.get());
        _soundHandler->PlaySoundEffect(Sound_effect::BALL);
    }

    if (Utilities::CheckCollision(_ballEnemy->GetBoxCollision(), _paddleEnemy->GetBoxCollision()))
    {
        _ballEnemy->CollisionDetected(_paddleEnemy.get());
        _soundHandler->PlaySoundEffect(Sound_effect::BALL);
    }

    if (Utilities::CheckCollision(_ballPlayer->GetBoxCollision(), _ballEnemy->GetBoxCollision()))
    {
        _ballPlayer->CollisionDetected(_ballEnemy.get());
        _ballEnemy->CollisionDetected(_ballPlayer.get());
        _soundHandler->PlaySoundEffect(Sound_effect::BALL);
    }

    for (int i = 0; i < _blocks.size(); i++)
    {
        bool ballBlockEnemy = false;
        bool ballBlockPlayer = false;

        ballBlockPlayer = Utilities::CheckCollision(_blocks[i]->GetBoxCollision(), _ballPlayer->GetBoxCollision());
        if (!ballBlockPlayer)
            ballBlockEnemy = Utilities::CheckCollision(_blocks[i]->GetBoxCollision(), _ballEnemy->GetBoxCollision());

        if (ballBlockPlayer || ballBlockEnemy)
        {
            _soundHandler->PlaySoundEffect(Sound_effect::BLOCK);
            Logger::LogLibrary("REMOVE ", _blocks[i]->GetTag() + " Size: " + std::to_string(_blocks.size()));

            if (ballBlockEnemy)
            {
                _ballEnemy->CollisionDetected(_blocks[i]);
            }
            if (ballBlockPlayer)
            {
                _ballPlayer->CollisionDetected(_blocks[i]);
            }

            _blocks.erase(_blocks.begin() + i);
        }
    }

    if (_blocks.size() <= 0)
    {
        _currentGameState = Game_State::GAME_OVER;
    }
}

/**
 * Set the display text.
 */
void GameController::SetMenuText()
{
    float propWidth = _window->GetScreenWidth() / 3;
    float propHeight = _window->GetScreenHeight() / 6;

    switch (_currentGameState)
    {
    case Game_State::MENU:
        _uiDisplay->SetText(" Press  S  to start ");
        _uiDisplay->SetSize({propWidth, propHeight});
        _uiDisplay->SetPosition({propWidth, propHeight});
        break;
    case Game_State::PLAYING:
        _uiDisplay->SetText("P1: " + std::to_string(_ballPlayer->GetScore()) + " | P2: " + std::to_string(_ballEnemy->GetScore()));
        _uiDisplay->SetSize({propWidth, 30});
        _uiDisplay->Reset();
        break;
    case Game_State::GAME_OVER:
        _uiDisplay->SetText("\nP2 Score: " + std::to_string(_ballEnemy->GetScore()) + "\nYour Score: " + std::to_string(_ballPlayer->GetScore()) + " \nYour Best Score:" + std::to_string(_bestScore) + "\nPress  S  to start ");
        _uiDisplay->SetSize({propWidth * 2, propHeight * 3});
        _uiDisplay->SetPosition({propWidth / 2, propHeight});
        break;
    default:
        break;
    }
}

/**
 * Reset all the objects to play again.
 */
void GameController::ResetGame()
{
    if (_ballPlayer->GetScore() > _bestScore)
        Utilities::SaveBestScore(_ballPlayer->GetScore());
    SpawnBlocks();
    _ballPlayer->Reset();
    _ballEnemy->Reset();
    _paddlePlayer->Reset();
    _paddleEnemy->Reset();
    LoadBestScore();
}

/**
 * Load the Best score.
 */
void GameController::LoadBestScore()
{
    _bestScore = Utilities::ReadBestScore();
}

/**
 * Initializes the music.
 */
void GameController::InitializeSound()
{
    _soundHandler = std::make_unique<SoundHandler>();
    _soundHandler->Initialize();
}