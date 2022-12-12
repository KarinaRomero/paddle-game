#include "texture_component.h"
#include "logger.h"
#include "SDL2/SDL_image.h"

TextureComponent::TextureComponent()
{
    _texture = NULL;
}

TextureComponent::~TextureComponent()
{
}

void TextureComponent::LoadTexture(std::string path, SDL_Renderer *worldRenderer, SDL_Surface *worldSurface)
{
    SDL_Surface* surface = GenerateSurface(path, worldSurface);
    _texture = SDL_CreateTextureFromSurface(worldRenderer, surface);
    
    SDL_FreeSurface(surface);
}

SDL_Surface *TextureComponent::GenerateSurface(std::string path, SDL_Surface *worldSurface)
{
    SDL_Surface *optimizedSurface = NULL;
    SDL_Surface *tempSurface = IMG_Load(path.c_str());

    if (worldSurface == NULL || tempSurface == NULL)
        Logger::LogLibraryError("Window::Initialize > GenerateSurface ", SDL_GetError());

    optimizedSurface = SDL_ConvertSurface(tempSurface, worldSurface->format, 0);

    if (optimizedSurface == NULL)
        Logger::LogLibraryError("Window::Initialize > SDL_ConvertSurface ", SDL_GetError());

    SDL_FreeSurface(tempSurface);
    return optimizedSurface;
}

void TextureComponent::RemoveTexture()
{
    if(_texture != NULL)
        SDL_DestroyTexture(_texture);
}
