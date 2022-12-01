#include <iostream>
#include <string>

#include "logger.h"
#include "window.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL.h"

Window::Window()
{
    // Initialize values by default
    _screenWidth = SCREEN_WIDTH;
    _screenHeight = SCREEN_HEIGHT;
    _windowName = "Window";

    _window = NULL;
    _renderer = NULL;
    _texture = NULL;
    _surface = NULL;
}

Window::Window(int screenWidth, int screenHeight, std::string windowName) : _screenWidth(screenWidth), _screenHeight(screenHeight), _windowName(windowName)
{
    _window = NULL;
    _renderer = NULL;
    _texture = NULL;
    _surface = NULL;
}

bool Window::Initialize()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        Logger::LogLibraryError("Window::Initialize > SDL_Init ", SDL_GetError());
        return false;
    }
    _window = SDL_CreateWindow(
        _windowName.c_str(),
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        _screenWidth,
        _screenHeight,
        0);

    if (_window == NULL)
    {
        Logger::LogLibraryError("Window::Initialize > SDL_CreateWindow ", SDL_GetError());
        return false;
    }

    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (_window == NULL)
    {
        Logger::LogLibraryError("Window::Initialize > SDL_CreateRenderer ", SDL_GetError());
        return false;
    }
    _currentWindowState = Window_State::WINDOW_RUNNING;

    return true;
}

void Window::LoadTexture(std::string path)
{
    _surface = IMG_Load(path.c_str());
    if (_surface)
    {
        _texture = SDL_CreateTextureFromSurface(_renderer, _surface);
    }
}

void Window::Render()
{
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);

    SDL_RenderClear(_renderer);

    SDL_RenderCopy(_renderer, _texture, NULL, NULL);

    SDL_RenderPresent(_renderer);
}

void Window::Input()
{
    SDL_Event _eventSDL;
    SDL_PollEvent(&_eventSDL);

    if (_eventSDL.type == SDL_QUIT)
        ClearAndQuit();
    else if (_eventSDL.type == SDL_KEYDOWN)
    {
        switch (_eventSDL.key.keysym.sym)
        {
        case SDLK_UP:
        case SDLK_w:
            Logger::LogLibrary("Window::Input ", "SDL_KEYDOWN UP or W ");
            break;
        case SDLK_DOWN:
        case SDLK_s:
            Logger::LogLibrary("Window::Input ", "SDL_KEYDOWN DOWN or s ");
            break;
        default:
            break;
        }
    }
}

void Window::ClearAndQuit()
{
    SDL_FreeSurface(_surface);
    SDL_DestroyWindow(_window);
    SDL_Quit();
    _currentWindowState = Window_State::WINDOW_FINISHED;
}
