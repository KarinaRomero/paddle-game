#include "block.h"
#include "logger.h"

Block::Block(/* args */)
{
}

Block::Block(Utilities::Vector2D position, Utilities::Vector2D size) : GameObject()
{
    Logger::LogLibrary("Block::Block ", "SDL Rect Shape by default");
    _size = size;
    _position = position;
    _boxCollision.w = _size.x;
    _boxCollision.h = _size.y;
    
    _boxCollision.x = _position.x;
    _boxCollision.y = _position.y;
}

void Block::Draw(SDL_Renderer* renderer)
{
    DrawRectShape(renderer);
}

void Block::DrawRectShape(SDL_Renderer *renderer)
{
    SDL_FRect rr = {_position.x, _position.y, _size.x, _size.y};
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
    SDL_RenderFillRectF(renderer, &rr);
}

Block::~Block()
{
}