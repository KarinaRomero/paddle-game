#include "ball.h"
#include "logger.h"

Ball::Ball()
{
    Logger::LogLibraryError("Ball::Ball ", "Ball::Ball Creation");
    _path = "../resources/ball.png";
    _size = {45, 45};
    _position = {50, 50};
    _velocity = {80, 80};
}


Ball::Ball(std::string path, Utilities::Vector2D position)
{
    Logger::LogLibraryError("Ball::Ball ", path);
    _path = path;
    _size = {45, 45};
    _position = position;
    _velocity = {280, 280};
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
