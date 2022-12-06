#include <string>
#include "logger.h"
#include "game.h"
#include "ball.h"

Game::Game()
{
    _window = new Window();
    _isGameInitialized = _window->Initialize();
}

Game::~Game()
{
}

void Game::Run()
{
    if (!_isGameInitialized)
        Logger::LogLibraryError("Game::Run() ", "Game cannot be initialized");
    else
    {
        /*std::string path = "../resources/ball.png";
        _window->LoadTexture(path);*/
        /*Ball *ball = new Ball();
        ball->Initialize(_window->_renderer, _window->_surface);*/

        Ball *ball = new Ball();
        ball->Initialize(_window->_renderer, _window->_surface);
        
        while (_window->GetCurrentWindowState() == Window_State::WINDOW_RUNNING)
        {
            _window->Input();
            _window->ClearRender();
            //_window->Render(ball->GetTextureComponent()->_texture, ball->GetPosition().y, ball->GetPosition().y, ball->GetSize().x, ball->GetSize().y);
            //_window->Render(ball->GetTextureComponent()->_texture, 50, 50, 70, 70);
            ball->Draw(_window->_renderer);
            ball->Update();
            _window->UpdateRender();
        }
    }
}
