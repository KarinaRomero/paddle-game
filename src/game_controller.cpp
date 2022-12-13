#include <string>
#include "logger.h"
#include "game_controller.h"

GameController::GameController()
{
    _window = new Window();
    _isGameInitialized = _window->Initialize();

    if (_isGameInitialized)
    {
        float propWidth = _window->GetScreenWidth() / 3;
        float propHeight = _window->GetScreenHeight() / 2;

        ballPlayer = new Ball("../resources/ball.png", {propWidth, propHeight});
        ballPlayer->Initialize(_window->GetRenderer(), _window->GetSurface());

        ballEnemy = new Ball("../resources/enemy-ball.png", {propWidth * 2, propHeight});
        ballEnemy->Initialize(_window->GetRenderer(), _window->GetSurface());

        paddlePlayer = new Paddle("../resources/paddle.png", {10, propHeight});
        paddlePlayer->Initialize(_window->GetRenderer(), _window->GetSurface());

        paddleEnemy = new Paddle("../resources/paddle1.png", {static_cast<float>(_window->GetScreenWidth() - 50), propHeight});
        paddleEnemy->Initialize(_window->GetRenderer(), _window->GetSurface());

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
            int input = _window->Input();
            paddlePlayer->SendInput(input);

            // Physics
            ballPlayer->Update();
            ballEnemy->Update();
            paddlePlayer->Update();
            paddleEnemy->Update();

            CheckCollisions();

            // Render
            _window->ClearRender();
            ballPlayer->Draw(_window->GetRenderer());
            ballEnemy->Draw(_window->GetRenderer());
            paddlePlayer->Draw(_window->GetRenderer());
            paddleEnemy->Draw(_window->GetRenderer());

            for (auto block : blocks)
                block->Draw(_window->GetRenderer());

            _window->UpdateRender();

            endTicks = SDL_GetTicks() - startTicks;

            if (endTicks < DELAY)
                SDL_Delay((int)(DELAY - endTicks));
        }

        ballPlayer->Clean();
        ballEnemy->Clean();
        paddlePlayer->Clean();
        paddleEnemy->Clean();

        _window->ClearAndQuit();
    }
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
                blocks.emplace_back(new Block({startW, startH}));
            startH += 20;
            Logger::LogLibraryWarning("SPAWN BLOCKS row: ", std::to_string(startW * row) + " col: " + std::to_string(startW * row));
        }
        startW += 15;
    }
}

void GameController::CheckCollisions()
{
    if (Utilities::CheckCollision(ballPlayer->GetBoxCollision(), paddlePlayer->GetBoxCollision()))
    {
        ballPlayer->SetDirectionX();
    }

    if (Utilities::CheckCollision(ballEnemy->GetBoxCollision(), paddleEnemy->GetBoxCollision()))
    {
        ballEnemy->SetDirectionX();
    }

    for (int i = 0; i < blocks.size(); i++)
    {
        bool ballBlockPlayer = Utilities::CheckCollision(blocks[i]->GetBoxCollision(), ballPlayer->GetBoxCollision());
        bool ballBlockEnemy = Utilities::CheckCollision(blocks[i]->GetBoxCollision(), ballEnemy->GetBoxCollision());

        if (ballBlockPlayer || ballBlockEnemy)
        {
            blocks.erase(blocks.begin() + i);

            if (ballBlockEnemy)
                ballEnemy->SetDirectionX();
            if (ballBlockPlayer)
                ballPlayer->SetDirectionX();
        }
    }
}