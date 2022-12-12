#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "window.h"
#include "ball.h"
#include "paddle.h"

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

    Ball *ballPlayer;
    Ball *ballEnemy;
    Paddle *paddlePlayer;
    Paddle *paddleEnemy;

    const int FPS = 60;
    const int DELAY =  1000 / FPS;
    
    // GameLoop
    void ProcessInput();
    void Update();
    void Render();
};

#endif