#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "game_object.h"

class Background : public GameObject
{
public:
    // Custom constructor for background
    Background(std::string path, Utilities::Vector2D position, Utilities::Vector2D size);
    ~Background();
};

#endif