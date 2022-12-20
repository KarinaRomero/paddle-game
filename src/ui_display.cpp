#include "ui_display.h"
#include "logger.h"

UIDisplay::UIDisplay(std::string path, Utilities::Vector2D position, Utilities::Vector2D size) : GameObject(path, position)
{
    Logger::LogLibrary("Block::Block ", "SDL Rect Shape by default");
    _size = size;
}

UIDisplay::~UIDisplay()
{
}

void UIDisplay::Update()
{
}

void UIDisplay::CollisionDetected(GameObject* other)
{
}