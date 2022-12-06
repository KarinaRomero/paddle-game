#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "texture_component.h"
#include "utilities.h"

class GameObject
{
private:
    TextureComponent *_texture;

protected:
    Utilities::Vector2D _size = {0, 0};
    Utilities::Vector2D _velocity = {0, 0};
    Utilities::Vector2D _position = {0, 0};
    std::string _path;

    TextureComponent _textureComponent;

public:
    GameObject();
    ~GameObject();
    void Initialize(SDL_Renderer *worldRenderer, SDL_Surface *worldSurface);

    TextureComponent *GetTextureComponent() { return _texture; };
    Utilities::Vector2D GetSize() { return _size; };
    Utilities::Vector2D GetPosition() { return _position; };

    void Update();
    void Draw(SDL_Renderer* renderer);
    void Clean();
};

#endif