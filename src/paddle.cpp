#include "paddle.h"
#include "logger.h"

Paddle::Paddle(/* args */)
{
}

Paddle::Paddle(std::string path, Utilities::Vector2D position) : GameObject(path, position)
{
    Logger::LogLibrary("Paddle::Paddle", "Custom");
    _size = {35, 95};
}

Paddle::~Paddle()
{
}