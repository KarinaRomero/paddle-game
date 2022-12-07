#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "window.h"

class GameController
{
public:
    GameController();
    ~GameController();
    void Run();

private:
    // Variables
    Window *_window;
    bool _isGameInitialized = false;

    const int FPS = 60;
    const int DELAY =  1000 / FPS;
    
    // GameLoop
    void ProcessInput();
    void Update();
    void Render();
};

#endif