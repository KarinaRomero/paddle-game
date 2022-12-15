#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "vector"
#include <map>
#include <string>
#include "window.h"
#include "ball.h"
#include "paddle.h"
#include "block.h"
#include "utilities.h"

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

    std::vector<Block*> blocks;
    std::map<std::string, Utilities::Collision_state> _ballPaddleCollisions;

    const int FPS = 60;
    const int DELAY =  1000 / FPS;
    
    void SpawnBlocks();

    // GameLoop
    void ProcessInput();
    void Update();
    void CheckCollisions();
    void Render();
    void Clear();
    int BrainPaddleInputValue();
    void RegisterCollisions();
    void CheckBounds(Ball* ball);
    void CheckBallPaddleCollision(Ball* objectA, Paddle* objectB);
};

#endif