#ifndef PADDLE_H
#define PADDLE_H

#include "game_object.h"

class Paddle : public GameObject
{
private:
public:
    Paddle();
    Paddle(std::string path, Utilities::Vector2D position);
    ~Paddle();
};

#endif