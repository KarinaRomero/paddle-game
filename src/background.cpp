#include "background.h"
#include "logger.h"


Background::Background(std::string path, Utilities::Vector2D position, Utilities::Vector2D size):GameObject(path, position)
{
    _size = size;
    _boxCollision = {0,0,0,0};
    Logger::LogLibrary("GameObject::GameObject ", path + "-----------------");
}

Background::~Background()
{
}