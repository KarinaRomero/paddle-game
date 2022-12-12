#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "texture_component.h"
#include "utilities.h"

class GameObject
{
private:
    TextureComponent *_textureComponent;

protected:
    std::string _path;
    Utilities::Vector2D _size = {0, 0};
    Utilities::Vector2D _velocity = {0, 0};
    Utilities::Vector2D _position = {0, 0};
    SDL_Rect _boxCollision = {0, 0, 0, 0};

public:
    GameObject();
    GameObject(std::string path, Utilities::Vector2D position);
    ~GameObject();
    void Initialize(SDL_Renderer *worldRenderer, SDL_Surface *worldSurface);

    Utilities::Vector2D GetSize() { return _size; };
    Utilities::Vector2D GetPosition() { return _position; };
    SDL_Rect GetBoxCollision() { return _boxCollision; };

    void Update();
    void Draw(SDL_Renderer* renderer);
    void Clean();
};

#endif