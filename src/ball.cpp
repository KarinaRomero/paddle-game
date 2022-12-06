#include "ball.h"
#include "logger.h"

Ball::Ball()
{
    Logger::LogLibraryError("Ball::Ball ", "Ball::Ball Creation");
    _path = "../resources/ball.png";
    _size = {45, 45};
    _position = {50, 50};
}

Ball::~Ball()
{
}

void Ball::Update()
{
    _position.x += 0.1;
    _position.y += 0.1;
}
