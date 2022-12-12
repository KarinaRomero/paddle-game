#include "paddle.h"
#include "logger.h"

Paddle::Paddle(/* args */)
{
}

Paddle::Paddle(std::string path, Utilities::Vector2D position) : GameObject(path, position)
{
    Logger::LogLibrary("Paddle::Paddle", "Custom");
    _velocity = {5, 5};
    _size = {35, 95};
    _boxCollision.w = _size.x;
    _boxCollision.h = _size.y;
}

Paddle::~Paddle()
{
}

void Paddle::SendInput(int input)
{
    if (input != 0)
    {
        _position.y += _velocity.y * input;
        _boxCollision.x = _position.x;
        _boxCollision.y = _position.y;
        Logger::LogLibrary("Paddle::SendInput", "input");
    }
}

void Paddle::Update()
{
}