#include <iostream>
#include <string>

#include "logger.h"
#include "window.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"

/**
 * Constructor default.
 *
 */
Window::Window()
{
    // Initialize values by default
    _screenWidth = SCREEN_WIDTH;
    _screenHeight = SCREEN_HEIGHT;
    _windowName = "Paddle Game";

    _window = NULL;
    _renderer = NULL;
    _surface = NULL;
}
/**
 * Custom constructor.
 *
 * Sets the general configurations for this window.
 *
 * @param screenWidth the size of the window width in pixels.
 * @param screenHeight he size of the window height in pixels.
 * @param windowName the name to display in the window.
 */
Window::Window(int screenWidth, int screenHeight, std::string windowName) : _screenWidth(screenWidth), _screenHeight(screenHeight), _windowName(windowName)
{
    _window = NULL;
    _renderer = NULL;
    _surface = NULL;
}

/**
 * Initialize all the objects necessary for this window
 * SDL_video, the window, the renderer, image, mixer and ttf.
 *
 * @return false if any of them can be initialized.
 */
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

    if (_renderer == NULL)
    {
        Logger::LogLibraryError("Window::Initialize > SDL_CreateRenderer ", SDL_GetError());
        return false;
    }

    _surface = SDL_GetWindowSurface(_window);

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
    {
        Logger::LogLibraryError("Window::Initialize > Init_Image ", IMG_GetError());
        return false;
    }

    if (TTF_Init() == -1)
    {
        Logger::LogLibraryError("Window::Initialize > Init_TTF", TTF_GetError());
        return false;
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        Logger::LogLibraryError("Window::Initialize > Mix_OpenAudio", Mix_GetError());
        return false;
    }

    _currentWindowState = Window_State::WINDOW_RUNNING;

    return true;
}

/**
 * Clear the renderer to dispose any existing cached frame
 */
void Window::ClearRender()
{
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(_renderer);
}

/**
 * Update the renderer performer
 */
void Window::UpdateRender()
{
    SDL_RenderPresent(_renderer);
}

/**
 * Listen if a key was pressed
 */
int Window::Input()
{
    int inputValue = 0;
    SDL_Event _eventSDL;
    // SDL_PollEvent(&_eventSDL);
    while (SDL_PollEvent(&_eventSDL))
    {
        if (_eventSDL.type == SDL_QUIT)
            _currentWindowState = Window_State::WINDOW_FINISHED;
        else if (_eventSDL.type == SDL_KEYDOWN)
        {
            switch (_eventSDL.key.keysym.sym)
            {
            case SDLK_UP:
            case SDLK_w:
                inputValue = -1;
                // Logger::LogLibrary("Window::Input ", "SDL_KEYDOWN UP or W ");
                break;
            case SDLK_DOWN:
            case SDLK_s:
                inputValue = 1;
                // Logger::LogLibrary("Window::Input ", "SDL_KEYDOWN DOWN or s ");
                break;
            default:
                break;
            }
        }
    }
    return inputValue;
}

/**
 * Free all the resources and Quit mixer, ttf, image and SDL
 */
Window::~Window()
{
    SDL_FreeSurface(_surface);
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    
    _window = NULL;
    _renderer = NULL;
    _surface = NULL;
    
	Mix_Quit();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}
