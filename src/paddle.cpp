#include "paddle.h"
#include "logger.h"

Paddle::Paddle(/* args */)
{
}

Paddle::Paddle(std::string path, Utilities::Vector2D position, Utilities::Vector2D moveMinMax) : GameObject(path, position)
{
    Logger::LogLibrary("Paddle::Paddle", "Custom");
    _moveMinMax = moveMinMax;
    _velocity = {30, 30};
    _size = {25, 125};
    _boxCollision.w = _size.x;
    _boxCollision.h = _size.y;

    _boxCollision.x = _position.x;
    _boxCollision.y = _position.y;
}

Paddle::~Paddle()
{
}

void Paddle::SendInput(int input)
{
    if (input != 0)
    {
        if ((input < 0 && _position.y >= _moveMinMax.x) || (input > 0 && _position.y + _size.y <= _moveMinMax.y))
        {
            _position.y += _velocity.y * input;
            _boxCollision.x = _position.x;
            _boxCollision.y = _position.y;
            // Logger::LogLibrary("Paddle::SendInput", "input");
        }
    }
    _currentState =  input;
}

void Paddle::Update()
{
}