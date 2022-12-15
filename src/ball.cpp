#include "ball.h"
#include "logger.h"

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

void Ball::CollisionDetected(Utilities::Collision_state collisionState)
{
    if(collisionState == Utilities::Collision_state::ENTER)
    {
        _velocity.x *= -1;
        Logger::LogLibrary("Ball::CollisionDetected " + _tag , std::to_string(Utilities::Collision_state::ENTER));
    }
}