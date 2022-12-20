#include "utilities.h"
#include <cmath>
#include <iostream>
#include <fstream> 

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

int Utilities::BrainPaddleInputValue(SDL_Rect objectA, SDL_Rect objectB)
{
    std::random_device randomDevice;
    std::mt19937 generator(randomDevice());
    std::uniform_int_distribution<int> distribution(0, 100);

    bool moveProbability = distribution(generator) < 75;

    if (moveProbability)
        return 0;

    auto pbDistanceX = abs(objectA.x - objectB.x);

    if (pbDistanceX > 100 || pbDistanceX < 20 || objectB.x > objectA.x)
        return 0;
    else if (objectB.y > objectA.y)
        return 1;
    else if (objectB.y < objectA.y)
        return -1;
    return 0;
}

int Utilities::ReadBestScore()
{
    std::string line;
    int score = 0;
    std::ifstream stream(savePath);
    if (stream.is_open())
    {
        std::getline(stream, line);
        score = std::stoi(line);
    }
    return score;
}

void Utilities::SaveBestScore(int score)
{
    std::ofstream SaveFile(savePath);
    SaveFile << score;
    SaveFile.close();
}