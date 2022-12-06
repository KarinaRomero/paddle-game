#include "ball.h"
#include "logger.h"

Ball::Ball()
{
    Logger::LogLibraryError("Ball::Ball", "Default");
}

Ball::Ball(std::string path, Utilities::Vector2D position) : GameObject(path, position)
{
    Logger::LogLibraryError("Ball::Ball", "Custom");
    _size = {45, 45};
}

Ball::~Ball()
{
}

void Ball::Update(float time)
{
    if(_position.x >= 640 ||  _position.x <= 0)
    {
        _velocity.x *= -1;
    }
    if(_position.y >= 480 || _position.y <= 0)
    {
        _velocity.y *= -1;
    }

    _position.x += _velocity.x * time;
    _position.y += _velocity.y * time;
}
