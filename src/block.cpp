#include "block.h"
#include "logger.h"

Block::Block(/* args */)
{
}

Block::Block(Utilities::Vector2D position, std::string tag) : GameObject()
{
    Logger::LogLibrary("Block::Block ", "SDL Rect Shape by default");
    _tag = tag;
    _position = position;
    _size = {15,20};
    _boxCollision.w = _size.x;
    _boxCollision.h = _size.y;
    _boxCollision.x = _position.x;
    _boxCollision.y = _position.y;

    _currentColorSelected = Utilities::RandomNumberByRates(_rates);
    
    r = _colors[_currentColorSelected].r;
    g = _colors[_currentColorSelected].g;
    b = _colors[_currentColorSelected].b;

    _points = _currentColorSelected + 1 * 100;
}

void Block::Draw(SDL_Renderer* renderer)
{
    DrawRectShape(renderer);
}

void Block::DrawRectShape(SDL_Renderer *renderer)
{
    SDL_FRect rr = {_position.x, _position.y, _size.x, _size.y};
    SDL_SetRenderDrawColor(renderer, r, g, b, alpha);
    SDL_RenderFillRectF(renderer, &rr);
}

Block::~Block()
{
}

