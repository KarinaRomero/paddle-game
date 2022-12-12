#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

enum Window_State
{
    WINDOW_RUNNING,
    WINDOW_FINISHED
};

class Window
{
public:
    SDL_Window *_window;
    SDL_Renderer *_renderer;
    SDL_Texture *_texture;
    SDL_Surface *_surface;

    Window();
    Window(int screenWidth, int screenHeight, std::string windowName);
    ~Window();

    bool Initialize();
    void LoadTexture(std::string path);
    void ClearRender();
    void UpdateRender();
    int Input();
    void ClearAndQuit();
    bool CheckCollision(SDL_Rect objectA, SDL_Rect objectB);
    int GetScreenWidth() {return _screenWidth;};
    int GetScreenHeight() {return _screenHeight;};

    Window_State GetCurrentWindowState() {return _currentWindowState;};

private:
    /*SDL_Window *_window;
    SDL_Renderer *_renderer;
    SDL_Texture *_texture;
    SDL_Surface *_surface;*/

    // Current window state
    Window_State _currentWindowState;

    // Configurations
    int _screenWidth;
    int _screenHeight;
    std::string _windowName;

    // Constant default values
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;

    // Methods
    SDL_Surface* GenerateSurface(std::string path);
};

#endif