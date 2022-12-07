#include "ball.h"
#include "logger.h"

Ball::Ball()
{
    Logger::LogLibrary("Ball::Ball", "Default");
}

Ball::Ball(std::string path, Utilities::Vector2D position) : GameObject(path, position)
{
    Logger::LogLibrary("Ball::Ball", "Custom");
    _size = {45, 45};
    _velocity = {5, 5};
}

Ball::~Ball()
{
}

void Ball::Update()
{
    if (_position.x >= 640 || _position.x <= 0)
    {
        _velocity.x *= -1;
    }
    if (_position.y >= 480 || _position.y <= 0)
    {
        _velocity.y *= -1;
    }

    _position.x += _velocity.x;
    _position.y += _velocity.y;
}
