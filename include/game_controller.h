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
#include "sound_handler.h"
#include "background.h"

enum Game_State 
{
    MENU,
    PLAYING,
    GAME_OVER
};

class GameController
{
public:
    // Constructor and destructor
    GameController();
    ~GameController();
    // Run the game
    void Run();

private:
    // Pointer to the window object
    Window *_window;
    bool _isGameInitialized = false;

    // Pointer to the GameObjects for the game
    Ball *_ballPlayer;
    Ball *_ballEnemy;
    Paddle *_paddlePlayer;
    Paddle *_paddleEnemy;
    UIDisplay* _uiDisplay;
    SoundHandler * _soundHandler;
    Background* _background;

    // The best score loaded
    int _bestScore;
    // Game state
    Game_State _currentGameState;
    // Current blocks spawned
    std::vector<Block*> _blocks;
    
    // Configurations to maintain the FPS
    const int FPS = 60;
    const int DELAY =  1000 / FPS;

    // Spawn
    void SpawnBlocks();
    void SpawnPlayers();
    void SetMenuText();
    void ResetGame();
    void LoadBestScore();
    void InitializeSound();

    // GameLoop
    void ProcessInput();
    void Update();
    void CheckCollisions();
    void Render();
    void Clear();
    void CheckBounds(Ball* ball);
};

#endif