#include "game_object.h"
#include "logger.h"

GameObject::GameObject()
{
    Logger::LogLibrary("GameObject::GameObject ", "Game Creation");
    _textureComponent = NULL;
}

GameObject::GameObject(std::string path, Utilities::Vector2D position)
{
    Logger::LogLibrary("GameObject::GameObject ", path);
    _path = path;
    _size = {0, 0};
    _position = position;
    _initialPosition = position;
    _velocity = {0, 0};
    _textureComponent = new TextureComponent();
}

void GameObject::Initialize(SDL_Renderer *worldRenderer, SDL_Surface *worldSurface)
{
    if (_textureComponent != NULL)
        _textureComponent->LoadTexture(_path, worldRenderer, worldSurface);
}

void GameObject::Initialize(std::string displayText, SDL_Renderer *worldRenderer, SDL_Surface *worldSurface, SDL_Color color)
{
    if (_textureComponent != NULL)
        _textureComponent->LoadTextureFont(_path, displayText, worldRenderer, worldSurface, color);
}

void GameObject::Draw(SDL_Renderer *renderer)
{
    if (_textureComponent != NULL)
        _textureComponent->Draw(renderer, _position, _size);
}
void GameObject::Draw(SDL_Renderer *renderer, std::string displayText, SDL_Color color)
{
    if (_textureComponent != NULL)
        _textureComponent->Draw(renderer, _position, _size, displayText, color);
}
void GameObject::Clean()
{
    _textureComponent->RemoveTexture();
}
void GameObject::CollisionDetected(GameObject* other){
    
}

void GameObject::Reset()
{
    _position = _initialPosition;
}