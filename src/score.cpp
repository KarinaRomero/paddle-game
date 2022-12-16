#include "score.h"
#include "logger.h"

Score::Score(std::string path, Utilities::Vector2D position, Utilities::Vector2D size) : GameObject(path, position)
{
    Logger::LogLibrary("Block::Block ", "SDL Rect Shape by default");
    _size = size;
}

Score::~Score()
{
}