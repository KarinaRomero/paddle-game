#ifndef BLOCK_H_
#define BLOCK_H_

#include "game_object.h"

class Block : public GameObject
{
private:
    void DrawRectShape(SDL_Renderer *renderer);
    Uint8 r;
    Uint8 g;
    Uint8 b;
public:
    Block(/* args */);
    Block(Utilities::Vector2D position);
    void Draw(SDL_Renderer* renderer);
    ~Block();
};
#endif