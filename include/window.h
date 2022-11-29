#include <string>

#include "SDL2/SDL.h"

class Window
{
public:
    Window();
    Window(int screenWidth, int screenHeight, std::string windowName);
    ~Window();

    void Initialize();
    void LoadTexture();
    void Update();
    void ClearAndQuit();

private:
    SDL_Window *_window;
    SDL_Renderer *_renderer;
    SDL_Texture *_texture;
    SDL_Event eventSDL;

    // Configurations
    int _screenWidth;
    int _screenHeight;
    std::string _windowName;

    // Constant default values
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;
    // Methods
};
