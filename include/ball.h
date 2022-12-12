#ifndef BALL_H
#define BALL_H

#ifndef BALL_H_
#define BALL_H_

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

#endif