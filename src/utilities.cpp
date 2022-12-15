#include "utilities.h"
#include <cmath>

bool Utilities::CheckCollision(SDL_Rect objectA, SDL_Rect objectB)
{
    int leftA, leftB, rightA, rightB, topA, topB, bottomA, bottomB;

    leftA = objectA.x;
    rightA = objectA.x + objectA.w;
    topA = objectA.y;
    bottomA = objectA.y + objectA.h;

    leftB = objectB.x;
    rightB = objectB.x + objectB.w;
    topB = objectB.y;
    bottomB = objectB.y + objectB.h;

    if (bottomA <= topB || topA >= bottomB || rightA <= leftB || leftA >= rightB)
        return false;

    return true;
}

double Utilities::Distance(SDL_Rect objectA, SDL_Rect objectB)
{
    return std::sqrt(std::pow(objectB.x - objectA.x, 2) + std::pow(objectB.y - objectA.y, 2));
}

int Utilities::RandomNumberByRates(std::vector<int> rates)
{
    int randomNumber = rand() % 100;
    int counter = 0; 
    int rateAccumulated = 0; 

    for (int rate : rates)
    {
        rateAccumulated+=rate;
        if(randomNumber <= rateAccumulated)
            return counter;
        else
            counter++;
    }
    return counter;
}