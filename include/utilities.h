#ifndef UTILITIES_H_
#define UTILITIES_H_

#include "vector"
#include "SDL2/SDL.h"

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

    bool CheckCollision(SDL_Rect objectA, SDL_Rect objectB);
    double Distance(SDL_Rect objectA, SDL_Rect objectB);
    int RandomNumberByRates(std::vector<int> rates);
}

#endif