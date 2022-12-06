#include <string>
#include "logger.h"
#include "game_controller.h"
#include "ball.h"

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
    float lastUpdate = 0;

    if (!_isGameInitialized)
        Logger::LogLibraryError("Game::Run() ", "Game cannot be initialized");
    else
    {
        Ball *ball = new Ball("../resources/ball.png", Utilities::Vector2D{50, 50});
        ball->Initialize(_window->_renderer, _window->_surface);

        Ball *ball1 = new Ball("../resources/enemy-ball.png", Utilities::Vector2D{70, 70});
        ball1->Initialize(_window->_renderer, _window->_surface);

        int i = 0;
        while (_window->GetCurrentWindowState() == Window_State::WINDOW_RUNNING)
        {
            // Event
            _window->Input();

            // Physics
            Uint32 current = SDL_GetTicks();
            float time = (current - lastUpdate) / 1000.0f;
            
            ball1->Update(time);
            ball->Update(time);
            lastUpdate = current;

            // Render
            _window->ClearRender();
            ball->Draw(_window->_renderer);
            ball1->Draw(_window->_renderer);
            _window->UpdateRender();
        }
    }
}
