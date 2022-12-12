#ifndef BLOCK_H_
#define BLOCK_H_

#include "game_object.h"

class Block : public GameObject
{
private:
    void DrawRectShape(SDL_Renderer *renderer);
public:
    Block(/* args */);
    Block(Utilities::Vector2D position, Utilities::Vector2D size);
    void Draw(SDL_Renderer* renderer);
    ~Block();
};
#endif