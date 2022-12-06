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

    // GameLoop
    void ProcessInput();
    void Update();
    void Render();
};

#endif