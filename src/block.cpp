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
    _size = {15, 20};
    _boxCollision.w = _size.x;
    _boxCollision.h = _size.y;
    _boxCollision.x = _position.x;
    _boxCollision.y = _position.y;

    _currentColorSelected = Utilities::RandomNumberByRates(_rates);

    r = _colors[_currentColorSelected].r;
    g = _colors[_currentColorSelected].g;
    b = _colors[_currentColorSelected].b;

    _points = _pointValues[_currentColorSelected];
}

Block::Block(const Block &block): GameObject()
{
    Logger::LogLibrary("Block::Block ", "Rule of five copy constructor");
    _size = {0, 0};
    _velocity = {0, 0};
    _tag = block._tag;
    _position = block._position;

    _boxCollision.w = block._size.x;
    _boxCollision.h = block._size.y;
    _boxCollision.x = block._position.x;
    _boxCollision.y = block._position.y;
    _currentColorSelected = block._currentColorSelected;
    _points = block._pointValues[_currentColorSelected];
}

Block &Block::operator=(Block block)
{
    Logger::LogLibrary("Block::Block ", "Rule of five copy assignment");
    _size = {0, 0};
    _velocity = {0, 0};
    _tag = block._tag;
    _position = block._position;

    _boxCollision.w = block._size.x;
    _boxCollision.h = block._size.y;
    _boxCollision.x = block._position.x;
    _boxCollision.y = block._position.y;
    _currentColorSelected = block._currentColorSelected;
    _points = block._pointValues[_currentColorSelected];

    return *this;
}

Block::Block(Block&& block): GameObject()
{
    Logger::LogLibrary("Block::Block ", "Rule of five move constructor");
    _size = {0, 0};
    _velocity = {0, 0};
    _tag = block._tag;
    _position = block._position;

    _boxCollision.w = block._size.x;
    _boxCollision.h = block._size.y;
    _boxCollision.x = block._position.x;
    _boxCollision.y = block._position.y;
    _currentColorSelected = block._currentColorSelected;
    _points = block._pointValues[_currentColorSelected];
}


Block& Block::operator=(Block&& block)
{
    Logger::LogLibrary("Block::Block ", "Rule of five move assignment");
    _size = {0, 0};
    _velocity = {0, 0};
    _tag = block._tag;
    _position = block._position;

    _boxCollision.w = block._size.x;
    _boxCollision.h = block._size.y;
    _boxCollision.x = block._position.x;
    _boxCollision.y = block._position.y;
    _currentColorSelected = block._currentColorSelected;
    _points = block._pointValues[_currentColorSelected];

    return *this;
}

void Block::Draw(SDL_Renderer *renderer)
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
    Logger::LogLibrary("Block::Block ", "Rule of five destructor");
}
