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
        ballPlayer->Initialize(_window->_renderer, _window->_surface);

        ballEnemy = new Ball("../resources/enemy-ball.png", {propWidth * 2, propHeight});
        ballEnemy->Initialize(_window->_renderer, _window->_surface);

        paddlePlayer = new Paddle("../resources/paddle.png", {10, propHeight});
        paddlePlayer->Initialize(_window->_renderer, _window->_surface);

        paddleEnemy = new Paddle("../resources/paddle1.png", {static_cast<float>(_window->GetScreenWidth() - 50), propHeight});
        paddleEnemy->Initialize(_window->_renderer, _window->_surface);
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

            if (_window->CheckCollision(ballPlayer->GetBoxCollision(), paddlePlayer->GetBoxCollision()))
            {
                ballPlayer->SetDirectionX();
            }

            if (_window->CheckCollision(ballEnemy->GetBoxCollision(), paddleEnemy->GetBoxCollision()))
            {
                ballEnemy->SetDirectionX();
            }

            // Render
            _window->ClearRender();
            ballPlayer->Draw(_window->_renderer);
            ballEnemy->Draw(_window->_renderer);
            paddlePlayer->Draw(_window->_renderer);
            paddleEnemy->Draw(_window->_renderer);
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
