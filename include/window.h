#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

// Enum of the window states
enum Window_State
{
    WINDOW_RUNNING,
    WINDOW_FINISHED
};

class Window
{
public:
    // Constructors and destructor
    Window();
    Window(int screenWidth, int screenHeight, std::string windowName);
    ~Window();

    // Methods
    bool Initialize();
    void ClearRender();
    void UpdateRender();
    int Input();
    int GetScreenWidth()const { return _screenWidth; };
    int GetScreenHeight()const { return _screenHeight; };
    
    // Get and Set
    Window_State GetCurrentWindowState()const  { return _currentWindowState; };
    SDL_Window *GetWindow()const   { return _window; };
    SDL_Renderer *GetRenderer()const   { return _renderer; };
    SDL_Surface *GetSurface()const  {return _surface;};

private:
    // Window where the game will be rendered
    SDL_Window *_window;
    // Rendering state
    SDL_Renderer *_renderer;
    // Graphical global area where the objects can be renderer
    SDL_Surface *_surface;

    // Current window state
    Window_State _currentWindowState;

    // Configurations
    int _screenWidth;
    int _screenHeight;
    std::string _windowName;

    // Constant default values
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;
};

#endif