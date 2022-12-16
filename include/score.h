#ifndef SCORE_H_
#define SCORE_H_

#include "game_object.h"

class Score : public GameObject
{
public:
    Score(std::string path, Utilities::Vector2D position, Utilities::Vector2D size);
    ~Score();
    SDL_Color GetColor() { return _color; };

private:
    SDL_Color _color = {184, 144, 18};
};

#endif