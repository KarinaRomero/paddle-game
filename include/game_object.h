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
    std::string _tag = "";

public:
    GameObject();
    GameObject(std::string path, Utilities::Vector2D position);
    ~GameObject();
    void Initialize(SDL_Renderer *worldRenderer, SDL_Surface *worldSurface);

    void SetTag(std::string tagValue) { _tag = tagValue; };
    std::string GetTag(){return _tag;};
    Utilities::Vector2D GetSize() { return _size; };
    Utilities::Vector2D GetPosition() { return _position; };
    SDL_Rect GetBoxCollision() { return _boxCollision; };

    void CollisionDetected(Utilities::Collision_state collisionState);
    void Update();
    void Draw(SDL_Renderer *renderer);
    void Clean();
};

#endif