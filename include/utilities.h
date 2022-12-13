#ifndef UTILITIES_H_
#define UTILITIES_H_

#include "SDL2/SDL.h"

namespace Utilities
{
    struct Vector2D
    {
        float x;
        float y;
    };

    bool CheckCollision(SDL_Rect objectA, SDL_Rect objectB);
}

#endif