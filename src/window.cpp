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
}

Window::Window(int screenWidth, int screenHeight, std::string windowName) : _screenWidth(screenWidth), _screenHeight(screenHeight), _windowName(windowName)
{
}

void Window::Initialize()
{

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow(
        _windowName.c_str(),
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        _screenWidth,
        _screenHeight,
        0);

    _renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

void Window::LoadTexture()
{
    SDL_Surface *surface = IMG_Load("../resources/ball.png");
    if (surface)
    {
        _texture = SDL_CreateTextureFromSurface(_renderer, surface);
        SDL_FreeSurface(surface);
    }
}

void Window::Update()
{
    Logger::LogLibraryError("WINDOW", "Update()");
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);

    SDL_RenderClear(_renderer);

    SDL_RenderCopy(_renderer, _texture, NULL, NULL);

    SDL_RenderPresent(_renderer);
}

void Window::ClearAndQuit()
{
    SDL_Quit();
}

Window::~Window()
{
}
