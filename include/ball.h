#ifndef BALL_H
#define BALL_H

#include "game_object.h"
#include <string>

class Ball : public GameObject
{
public:
    Ball();
    Ball(std::string path, Utilities::Vector2D position);
    ~Ball();

    void Update();
    void SetDirectionX();
private:
};

# endif