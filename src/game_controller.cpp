#include "logger.h"
#include "game_controller.h"

GameController::GameController()
{
    _window = new Window();
    _isGameInitialized = _window->Initialize();

    if (_isGameInitialized)
    {
        float propWidth = _window->GetScreenWidth() / 4;
        float propHeight = _window->GetScreenHeight() / 2;

        ballPlayer = new Ball("../resources/ball.png", {propWidth, propHeight}, {0, 0}, {propWidth * 3, static_cast<float>(_window->GetScreenHeight())});
        ballPlayer->Initialize(_window->GetRenderer(), _window->GetSurface());
        ballPlayer->SetTag("BallPlayer");

        ballEnemy = new Ball("../resources/enemy-ball.png", {propWidth * 3, propHeight}, {propWidth,0}, {static_cast<float>(_window->GetScreenWidth()), static_cast<float>(_window->GetScreenHeight())});
        ballEnemy->Initialize(_window->GetRenderer(), _window->GetSurface());
        ballEnemy->SetTag("BallEnemy");

        paddlePlayer = new Paddle("../resources/paddle.png", {10, propHeight}, {0, static_cast<float>(_window->GetScreenHeight())});
        paddlePlayer->Initialize(_window->GetRenderer(), _window->GetSurface());
        paddlePlayer->SetTag("Player");

        paddleEnemy = new Paddle("../resources/paddle1.png", {static_cast<float>(_window->GetScreenWidth() - 50), propHeight}, {0, static_cast<float>(_window->GetScreenHeight())});
        paddleEnemy->Initialize(_window->GetRenderer(), _window->GetSurface());
        paddleEnemy->SetTag("PaddleEnemy");

        SpawnBlocks();
        RegisterCollisions();
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
    paddlePlayer->SendInput(input);
    //paddleEnemy->SendInput(BrainPaddleInputValue());
}

void GameController::Update()
{
    ballPlayer->Update();
    ballEnemy->Update();
    paddlePlayer->Update();
    paddleEnemy->Update();
}

void GameController::Render()
{
    ballPlayer->Draw(_window->GetRenderer());
    ballEnemy->Draw(_window->GetRenderer());
    paddlePlayer->Draw(_window->GetRenderer());
    paddleEnemy->Draw(_window->GetRenderer());

    for (auto block : blocks)
        block->Draw(_window->GetRenderer());
}

void GameController::Clear()
{
    ballPlayer->Clean();
    ballEnemy->Clean();
    paddlePlayer->Clean();
    paddleEnemy->Clean();
}

void GameController::SpawnBlocks()
{
    float startW = _window->GetScreenWidth() / 3;
    float startH = 0;

    float segmentsW = startW / 15;
    float segmentsH = _window->GetScreenHeight() / 20;

    for (int row = 1; row <= segmentsW; row++)
    {
        startH = 0;
        for (int col = 1; col <= segmentsH; col++)
        {
            if ((rand() % 100) < 50)
            {
                blocks.emplace_back(new Block({startW, startH}));
                ballPlayer->SetTag("Block" + std::to_string(row) + std::to_string(col));
            }
            startH += 20;
            // Logger::LogLibraryWarning("SPAWN BLOCKS row: ", std::to_string(startW * row) + " col: " + std::to_string(startW * row));
        }
        startW += 15;
    }
}

void GameController::CheckCollisions()
{
    CheckBallPaddleCollision(ballPlayer, paddlePlayer);
    CheckBallPaddleCollision(ballEnemy, paddleEnemy);

    for (int i = 0; i < blocks.size(); i++)
    {
        bool ballBlockPlayer = Utilities::CheckCollision(blocks[i]->GetBoxCollision(), ballPlayer->GetBoxCollision());
        bool ballBlockEnemy = Utilities::CheckCollision(blocks[i]->GetBoxCollision(), ballEnemy->GetBoxCollision());

        if (ballBlockPlayer || ballBlockEnemy)
        {
            Logger::LogLibrary("REMOVE ", blocks[i]->GetTag() + " Size: " + std::to_string(blocks.size()));
            blocks.erase(blocks.begin() + i);

            if (ballBlockEnemy)
                ballEnemy->CollisionDetected(Utilities::Collision_state::ENTER);
            if (ballBlockPlayer)
                ballPlayer->CollisionDetected(Utilities::Collision_state::ENTER);
        }
    }
}

int GameController::BrainPaddleInputValue()
{
    bool moveProbability = (rand() % 100) < 75;

    if (moveProbability)
        return 0;

    auto pbDistanceX = abs(paddleEnemy->GetBoxCollision().x - ballEnemy->GetBoxCollision().x);

    if (pbDistanceX > 100 || pbDistanceX < 20 || ballEnemy->GetBoxCollision().x > paddleEnemy->GetBoxCollision().x)
        return 0;
    else if (ballEnemy->GetBoxCollision().y > paddleEnemy->GetBoxCollision().y)
        return 1;
    else if (ballEnemy->GetBoxCollision().y < paddleEnemy->GetBoxCollision().y)
        return -1;
    return 0;
}

void GameController::RegisterCollisions()
{
    _ballPaddleCollisions.insert({ballPlayer->GetTag() + paddlePlayer->GetTag(), Utilities::Collision_state::ANY});
    _ballPaddleCollisions.insert({ballEnemy->GetTag() + paddleEnemy->GetTag(), Utilities::Collision_state::ANY});
}

void GameController::CheckBallPaddleCollision(Ball *objectA, Paddle *objectB)
{
    if (Utilities::CheckCollision(objectA->GetBoxCollision(), objectB->GetBoxCollision()))
    {
        if (_ballPaddleCollisions[objectA->GetTag() + objectB->GetTag()] == Utilities::ANY)
        {
            _ballPaddleCollisions[objectA->GetTag() + objectB->GetTag()] = Utilities::ENTER;
        }
        else if (_ballPaddleCollisions[objectA->GetTag() + objectB->GetTag()] == Utilities::ENTER)
        {
            _ballPaddleCollisions[objectA->GetTag() + objectB->GetTag()] = Utilities::STAY;
        }
        objectA->CollisionDetected(_ballPaddleCollisions[objectA->GetTag() + objectB->GetTag()]);
    }
    else if (_ballPaddleCollisions[objectA->GetTag() + objectB->GetTag()] == Utilities::STAY)
    {
        _ballPaddleCollisions[objectA->GetTag() + objectB->GetTag()] = Utilities::ANY;
    }
}