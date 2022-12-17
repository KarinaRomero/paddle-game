#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "vector"
#include <map>
#include <string>
#include "window.h"
#include "ball.h"
#include "paddle.h"
#include "block.h"
#include "score.h"
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
    Ball *_ballPlayer;
    Ball *_ballEnemy;
    Paddle *_paddlePlayer;
    Paddle *_paddleEnemy;
    Score* _scoreDisplay;
    std::string _scoreText = "";
    
    std::vector<Block*> _blocks;
    
    const int FPS = 60;
    const int DELAY =  1000 / FPS;

    // Spawn
    void SpawnBlocks();
    void SpawnPlayers();

    // GameLoop
    void ProcessInput();
    void Update();
    void CheckCollisions();
    void Render();
    void Clear();
    void CheckBounds(Ball* ball);
};

#endif