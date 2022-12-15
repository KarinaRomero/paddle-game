#ifndef BALL_H
#define BALL_H

#include "game_object.h"
#include <string>

class Ball : public GameObject
{
public:
    Ball();
    Ball(std::string path, Utilities::Vector2D position, Utilities::Vector2D min, Utilities::Vector2D max);
    ~Ball();

    void Update();
    void CollisionDetected(Utilities::Collision_state collisionState);
private:
    Utilities::Vector2D _moveLimitsMax;
    Utilities::Vector2D _moveLimitsMin;
};

#endif