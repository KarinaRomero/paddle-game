#include "ball.h"
#include "logger.h"

Ball::Ball()
{
    Logger::LogLibrary("Ball::Ball", "Default");
}

Ball::Ball(std::string path, Utilities::Vector2D position) : GameObject(path, position)
{
    Logger::LogLibrary("Ball::Ball", "Custom");
    _velocity = {5, 5};
    _size = {35, 35};
    _boxCollision.w = _size.x;
    _boxCollision.h = _size.y;
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

    _boxCollision.x = _position.x;
    _boxCollision.y = _position.y;
}

void Ball::SetDirectionX()
{
    _velocity.x *= -1;
    //Logger::LogLibrary("Collision Detected ", "ball and paddle");
}