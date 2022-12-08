#include "paddle.h"
#include "logger.h"

Paddle::Paddle(/* args */)
{
}

Paddle::Paddle(std::string path, Utilities::Vector2D position) : GameObject(path, position)
{
    Logger::LogLibrary("Paddle::Paddle", "Custom");
    _size = {35, 95};
    _velocity = {5, 5};
}

Paddle::~Paddle()
{
}

void Paddle::SendInput(int input)
{
    if (input != 0)
    {
        _position.y += _velocity.y * input;
        Logger::LogLibrary("Paddle::SendInput", "input");
    }
}

void Paddle::Update()
{ 
}