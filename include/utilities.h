#ifndef UTILITIES_H_
#define UTILITIES_H_

#include "vector"
#include "SDL2/SDL.h"
#include "string"

namespace Utilities
{
    enum Collision_state
    {
        ANY,
        ENTER,
        STAY
    };

    struct Vector2D
    {
        float x;
        float y;
    };

    const std::string savePath {"../resources/save.txt"};

    bool CheckCollision(SDL_Rect objectA, SDL_Rect objectB);
    double Distance(SDL_Rect objectA, SDL_Rect objectB);
    int RandomNumberByRates(std::vector<int> rates);
    int BrainPaddleInputValue(SDL_Rect objectA, SDL_Rect objectB);
    int ReadBestScore();
    void SaveBestScore(int score);
}

#endif