#ifndef BLOCK_H_
#define BLOCK_H_

#include "vector"
#include "game_object.h"

class Block : public GameObject
{
private:
    const std::vector<SDL_Color> _colors = {{18, 44, 184}, {80, 88, 133}, {47, 175, 235}, {237, 159, 107}, {184, 60, 18}};
    const std::vector<int> rates = {9, 10, 16, 22, 22, 22};
    int _points = 0;
    int _currentColorSelected;
    Uint8 r;
    Uint8 g;
    Uint8 b;
    void DrawRectShape(SDL_Renderer *renderer);
    void GenerateBlockType();
    
public:
    Block(/* args */);
    Block(Utilities::Vector2D position, std::string tag);
    void Draw(SDL_Renderer* renderer);
    int GetPoints(){return _points;};
    ~Block();
};
#endif