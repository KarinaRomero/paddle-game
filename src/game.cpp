#include <string>
#include "logger.h"
#include "game.h"

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
        std::string path = "../resources/ball.png";
        _window->LoadTexture(path);

        while (_window->GetCurrentWindowState() == Window_State::WINDOW_RUNNING)
        {
            _window->Render();
            _window->Input();
        }
    }
}
