#include "game_object.h"
#include "logger.h"

GameObject::GameObject()
{
    Logger::LogLibrary("GameObject::GameObject ", "Game Creation");
    _textureComponent = nullptr;
}

GameObject::GameObject(std::string path, Utilities::Vector2D position) : _position(position), _initialPosition(position), _path(path)
{
    Logger::LogLibrary("GameObject::GameObject ", path);
    _size = {0, 0};
    _velocity = {0, 0};
    _textureComponent = std::make_unique<TextureComponent>();
}

void GameObject::Initialize(SDL_Renderer *worldRenderer, SDL_Surface *worldSurface)
{
    if (_textureComponent != nullptr)
        _textureComponent->LoadTexture(_path, worldRenderer, worldSurface);
}

void GameObject::Initialize(std::string displayText, SDL_Renderer *worldRenderer, SDL_Surface *worldSurface, SDL_Color color)
{
    if (_textureComponent != nullptr)
        _textureComponent->LoadTextureFont(_path, displayText, worldRenderer, worldSurface, color);
}

void GameObject::Draw(SDL_Renderer *renderer)
{
    if (_textureComponent != nullptr)
        _textureComponent->Draw(renderer, _position, _size);
}
void GameObject::Draw(SDL_Renderer *renderer, std::string displayText, SDL_Color color)
{
    if (_textureComponent != nullptr)
        _textureComponent->Draw(renderer, _position, _size, displayText, color);
}
void GameObject::Clean()
{
    _textureComponent->RemoveTexture();
}

void GameObject::Reset()
{
    _position = _initialPosition;
}