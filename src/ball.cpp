#include "ball.h"
#include "logger.h"
#include "block.h"
#include "paddle.h"

#include <bits/stdc++.h>

Ball::Ball()
{
    Logger::LogLibrary("Ball::Ball", "Default");
}

Ball::Ball(std::string path, Utilities::Vector2D position, Utilities::Vector2D min, Utilities::Vector2D max) : GameObject(path, position)
{
    Logger::LogLibrary("Ball::Ball", "Custom");

    _moveLimitsMax = max;
    _moveLimitsMin = min;

    _velocity = {5, 5};
    _size = {25, 25};

    _boxCollision.w = _size.x;
    _boxCollision.h = _size.y;

    _boxCollision.x = _position.x;
    _boxCollision.y = _position.y;
}

Ball::~Ball()
{
}

void Ball::Update()
{
    if (_position.x >= _moveLimitsMax.x || _position.x <= _moveLimitsMin.x)
    {
        _velocity.x *= -1;
        _faults++;
        _score = std::clamp(_score - _faultValue, 0, _score - _faultValue);
    }
    if (_position.y >= _moveLimitsMax.y || _position.y <= _moveLimitsMin.y)
    {
        _velocity.y *= -1;
    }

    _position.x += _velocity.x;
    _position.y += _velocity.y;

    _boxCollision.x = _position.x;
    _boxCollision.y = _position.y;
}

void Ball::Reset()
{
    GameObject::Reset();
    _score = 0;
}

void Ball::CollisionDetected(GameObject *other)
{
    if (other->GetTag().find("Paddle") != std::string::npos || other->GetTag().find("Block") != std::string::npos || other->GetTag().find("Ball") != std::string::npos)
    {
        
        _velocity.x *= -1;

        if (other->GetTag().find("Block") != std::string::npos)
        {
            Block* block = dynamic_cast<Block*>(other);
            _score = std::clamp(_score + block->GetPoints(), 0, _score + block->GetPoints());
            delete block;
        }
    }
}