#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "vector"
#include <map>
#include <string>
#include "window.h"
#include "ball.h"
#include "paddle.h"
#include "block.h"
#include "ui_display.h"
#include "utilities.h"

enum Game_State 
{
    MENU,
    PLAYING,
    GAME_OVER
};

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
    UIDisplay* _uiDisplay;
    int _bestScore;

    Game_State _currentGameState;
    
    std::vector<Block*> _blocks;
    
    const int FPS = 60;
    const int DELAY =  1000 / FPS;

    // Spawn
    void SpawnBlocks();
    void SpawnPlayers();
    void SetMenuText();
    void ResetGame();
    void LoadBestScore();

    // GameLoop
    void ProcessInput();
    void Update();
    void CheckCollisions();
    void Render();
    void Clear();
    void CheckBounds(Ball* ball);

};

#endif