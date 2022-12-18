#include "logger.h"
#include "game_controller.h"

GameController::GameController()
{
    _window = new Window();
    _isGameInitialized = _window->Initialize();

    if (_isGameInitialized)
    {
        _currentGameState = Game_State::MENU;
        SpawnPlayers();
        SpawnBlocks();
    }
}

GameController::~GameController()
{
}

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
        _window->ClearAndQuit();
    }
}

void GameController::ProcessInput()
{
    int input = _window->Input();
    if(_currentGameState == Game_State::PLAYING)
    {
        _paddlePlayer->SendInput(input);
        _paddleEnemy->SendInput(Utilities::BrainPaddleInputValue(_paddleEnemy->GetBoxCollision(), _ballEnemy->GetBoxCollision()));
    }
    if(_currentGameState != Game_State::PLAYING && input > 0)
    {
        if(_currentGameState == Game_State::GAME_OVER)
            ResetGame();
        _currentGameState = Game_State::PLAYING;
    }
}

void GameController::Update()
{
    SetMenuText();
    if(_currentGameState == Game_State::PLAYING)
    {
        _ballPlayer->Update();
        _ballEnemy->Update();
        _paddlePlayer->Update();
        _paddleEnemy->Update();
    }
}

void GameController::Render()
{
    _ballPlayer->Draw(_window->GetRenderer());
    _ballEnemy->Draw(_window->GetRenderer());
    _paddlePlayer->Draw(_window->GetRenderer());
    _paddleEnemy->Draw(_window->GetRenderer());
    _uiDisplay->Draw(_window->GetRenderer(), _uiDisplay->GetText(), _uiDisplay->GetColor());

    for (auto block : _blocks)
        block->Draw(_window->GetRenderer());
}

void GameController::Clear()
{
    _ballPlayer->Clean();
    _ballEnemy->Clean();
    _paddlePlayer->Clean();
    _paddleEnemy->Clean();
}

void GameController::SpawnBlocks()
{
    float offset = 30;
    float startW = _window->GetScreenWidth() / 3;
    float startH = offset;

    float segmentsW = startW / 15;
    float segmentsH = (_window->GetScreenHeight()-offset) / 20;

    for (int row = 1; row <= segmentsW; row++)
    {
        startH = offset;
        for (int col = 1; col <= segmentsH; col++)
        {
            if ((rand() % 100) < 50)
            {
                _blocks.emplace_back(new Block({startW, startH}, "Block" + std::to_string(row) + std::to_string(col)));
            }
            startH += 20;
            // Logger::LogLibraryWarning("SPAWN BLOCKS row: ", std::to_string(startW * row) + " col: " + std::to_string(startW * row));
        }
        startW += 15;
    }
}

void GameController::SpawnPlayers()
{
    float propWidth = _window->GetScreenWidth() / 4;
    float propHeight = _window->GetScreenHeight() / 2;

    _ballPlayer = new Ball("../resources/ball.png", {propWidth, propHeight}, {0, 0}, {propWidth * 3, static_cast<float>(_window->GetScreenHeight())});
    _ballPlayer->Initialize(_window->GetRenderer(), _window->GetSurface());
    _ballPlayer->SetTag("BallPlayer");

    _ballEnemy = new Ball("../resources/enemy-ball.png", {propWidth * 3, propHeight}, {propWidth, 0}, {static_cast<float>(_window->GetScreenWidth()), static_cast<float>(_window->GetScreenHeight())});
    _ballEnemy->Initialize(_window->GetRenderer(), _window->GetSurface());
    _ballEnemy->SetTag("BallEnemy");

    _paddlePlayer = new Paddle("../resources/paddle.png", {10, propHeight}, {0, static_cast<float>(_window->GetScreenHeight())});
    _paddlePlayer->Initialize(_window->GetRenderer(), _window->GetSurface());
    _paddlePlayer->SetTag("PaddlePlayer");

    _paddleEnemy = new Paddle("../resources/paddle1.png", {static_cast<float>(_window->GetScreenWidth() - 50), propHeight}, {0, static_cast<float>(_window->GetScreenHeight())});
    _paddleEnemy->Initialize(_window->GetRenderer(), _window->GetSurface());
    _paddleEnemy->SetTag("PaddleEnemy");

    _uiDisplay = new UIDisplay("../resources/Acme-Regular.ttf", {propWidth, 0}, {propWidth, 30});
    _uiDisplay->Initialize(_uiDisplay->GetText(), _window->GetRenderer(), _window->GetSurface(), _uiDisplay->GetColor());
}

void GameController::CheckCollisions()
{
    if (Utilities::CheckCollision(_ballPlayer->GetBoxCollision(), _paddlePlayer->GetBoxCollision()))
        _ballPlayer->CollisionDetected(_paddlePlayer);

    if (Utilities::CheckCollision(_ballEnemy->GetBoxCollision(), _paddleEnemy->GetBoxCollision()))
        _ballEnemy->CollisionDetected(_paddleEnemy);

    if (Utilities::CheckCollision(_ballPlayer->GetBoxCollision(), _ballEnemy->GetBoxCollision()))
    {
        _ballPlayer->CollisionDetected(_ballEnemy);
        _ballEnemy->CollisionDetected(_ballPlayer);
    }

    for (int i = 0; i < _blocks.size(); i++)
    {
        bool ballBlockEnemy = false;
        bool ballBlockPlayer = false;
        
        ballBlockPlayer = Utilities::CheckCollision(_blocks[i]->GetBoxCollision(), _ballPlayer->GetBoxCollision());
        if(!ballBlockPlayer)
            ballBlockEnemy = Utilities::CheckCollision(_blocks[i]->GetBoxCollision(), _ballEnemy->GetBoxCollision());

        if (ballBlockPlayer || ballBlockEnemy)
        {
            Logger::LogLibrary("REMOVE ", _blocks[i]->GetTag() + " Size: " + std::to_string(_blocks.size()));
            
            if (ballBlockEnemy)
                _ballEnemy->CollisionDetected(std::move(_blocks[i]));
            if (ballBlockPlayer)
                _ballPlayer->CollisionDetected(std::move(_blocks[i]));

            _blocks.erase(_blocks.begin() + i);
        }
    }
    
    if(_blocks.size() <= 0)
    {
        _currentGameState = Game_State::GAME_OVER;
    }
}

void GameController::SetMenuText()
{
    switch (_currentGameState)
    {
        case Game_State::MENU:
            _uiDisplay->SetText(" Press  S  to start ");
            break;
        case Game_State::PLAYING:
            _uiDisplay->SetText( "P1: " + std::to_string(_ballPlayer->GetScore()) + " | P2: " + std::to_string(_ballEnemy->GetScore()));
            break;
        case Game_State::GAME_OVER:
            _uiDisplay->SetText(" Game Over!! \n Press  S  to start ");
            break;
        default:
            break;
    }
}

void GameController::ResetGame()
{
    SpawnBlocks();
    _ballPlayer->ResetPosition();
    _ballEnemy->ResetPosition();
    _paddlePlayer->ResetPosition();
    _paddleEnemy->ResetPosition();
}