#include "logger.h"
#include "game.h"

Game::Game()
{
    Logger::LogLibrary("Game", "Game() constructor");
    _window = new Window();
}

Game::~Game()
{
}

void Game::Run()
{
    _window->Initialize();
    _window->LoadTexture();
    while (true)
    {
        _window->Update();
    }
    _window->ClearAndQuit();
}

/*void Game::Update()
{
    Logger::LogLibraryError("WINDOW", "Update()");
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);

    SDL_RenderClear(_renderer);

    SDL_RenderCopy(_renderer, _texture, NULL, NULL);

    SDL_RenderPresent(_renderer);
}

void Game::ProcessInput()()
{
    SDL_PollEvent(&eventSDL);

    switch (eventSDL.type)
    {
    case SDL_QUIT:
        ClearAndQuit();
        break;

    default:
        break;
    }
}*/
