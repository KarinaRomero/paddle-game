#include "game_object.h"
#include "logger.h"

GameObject::GameObject()
{
    Logger::LogLibrary("GameObject::GameObject ", "Game Creation");
    _texture = new TextureComponent();
}

GameObject::GameObject(std::string path, Utilities::Vector2D position)
{
    Logger::LogLibrary("GameObject::GameObject ", path);
    _path = path;
    _size = {0, 0};
    _position = position;
    _velocity = {0, 0};
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

void GameObject::Clean()
{
    _texture->RemoveTexture();
}
