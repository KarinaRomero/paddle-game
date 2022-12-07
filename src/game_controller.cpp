#include <string>
#include "logger.h"
#include "game_controller.h"
#include "ball.h"
#include "paddle.h"

GameController::GameController()
{
    _window = new Window();
    _isGameInitialized = _window->Initialize();
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
        Ball *ball = new Ball("../resources/ball.png", Utilities::Vector2D{50, 50});
        ball->Initialize(_window->_renderer, _window->_surface);

        Ball *ball1 = new Ball("../resources/enemy-ball.png", Utilities::Vector2D{70, 70});
        ball1->Initialize(_window->_renderer, _window->_surface);

        Paddle *paddle = new Paddle("../resources/paddle.png", Utilities::Vector2D{70, 70});
        paddle->Initialize(_window->_renderer, _window->_surface);

        Paddle *paddle1 = new Paddle("../resources/paddle1.png", Utilities::Vector2D{270, 70});
        paddle1->Initialize(_window->_renderer, _window->_surface);

        Uint32 startTicks = 0;
        Uint32 endTicks = 0;

        while (_window->GetCurrentWindowState() == Window_State::WINDOW_RUNNING)
        {
            startTicks = SDL_GetTicks();

            // Event
            _window->Input();

            // Physics
            ball1->Update();
            ball->Update();

            // Render
            _window->ClearRender();
            ball->Draw(_window->_renderer);
            ball1->Draw(_window->_renderer);
            paddle->Draw(_window->_renderer);
            paddle1->Draw(_window->_renderer);
            _window->UpdateRender();

            endTicks = SDL_GetTicks() - startTicks;

            if (endTicks < DELAY)
                SDL_Delay((int)(DELAY - endTicks));
        }

        ball->Clean();
        ball1->Clean();
        paddle->Clean();
        paddle1->Clean();

        _window->ClearAndQuit();
    }
}
