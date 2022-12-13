#include "block.h"
#include "logger.h"

Block::Block(/* args */)
{
}

Block::Block(Utilities::Vector2D position) : GameObject()
{
    Logger::LogLibrary("Block::Block ", "SDL Rect Shape by default");
    _position = position;
    _size = {15,20};
    _boxCollision.w = _size.x;
    _boxCollision.h = _size.y;
    _boxCollision.x = _position.x;
    _boxCollision.y = _position.y;
    
    r = rand() % 255+1;
    g = rand() % 255+1;
    b = rand() % 255+1;
}

void Block::Draw(SDL_Renderer* renderer)
{
    DrawRectShape(renderer);
}

void Block::DrawRectShape(SDL_Renderer *renderer)
{
    SDL_FRect rr = {_position.x, _position.y, _size.x, _size.y};
    SDL_SetRenderDrawColor(renderer, r, g, b, 0xFF);
    SDL_RenderFillRectF(renderer, &rr);
}

Block::~Block()
{
    Logger::LogLibrary("Delete BLOCK ", "-------------------------------------");
}