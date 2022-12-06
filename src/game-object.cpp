#include "game-object.h"
#include "logger.h"

GameObject::GameObject()
{
    Logger::LogLibraryError("GameObject::GameObject ", "Game Creation");
    _texture = new TextureComponent();
}

GameObject::~GameObject()
{
}

void GameObject::Initialize(SDL_Renderer *worldRenderer, SDL_Surface *worldSurface)
{
    _texture->LoadTexture(_path, worldRenderer, worldSurface);
}

void GameObject::Draw(SDL_Renderer *renderer)
{
    SDL_FRect rr = {_position.x, _position.y, _size.x, _size.y};

    SDL_RenderCopyF(renderer, _texture->_texture, NULL, &rr);
}