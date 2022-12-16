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
void TextureComponent::LoadTextureFont(std::string path, std::string displayText, SDL_Renderer *worldRenderer, SDL_Surface *worldSurface, SDL_Color color)
{
    _font = TTF_OpenFont(path.c_str(), 48);

    if (_font == NULL)
        Logger::LogLibraryError("TextureComponent::LoadTextureFont > GenerateSurface ", TTF_GetError());

    SetTextureText(worldRenderer, displayText, color);
}

void TextureComponent::LoadTexture(std::string path, SDL_Renderer *worldRenderer, SDL_Surface *worldSurface)
{
    SDL_Surface *surface = GenerateSurface(path, worldSurface);
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

void TextureComponent::Draw(SDL_Renderer *renderer, Utilities::Vector2D position, Utilities::Vector2D size)
{
    SDL_FRect rr = {position.x, position.y, size.x, size.y};

    SDL_RenderCopyF(renderer, _texture, NULL, &rr);
}

void TextureComponent::Draw(SDL_Renderer *renderer, Utilities::Vector2D position, Utilities::Vector2D size, std::string displayText, SDL_Color color)
{
    SetTextureText(renderer, displayText, color);
    Draw(renderer, position, size);
}

void TextureComponent::SetTextureText(SDL_Renderer *renderer, std::string displayText, SDL_Color color)
{
    SDL_Surface *textSurface = TTF_RenderText_Solid(_font, displayText.c_str(), color);

    if (textSurface == NULL)
        Logger::LogLibraryError("Window::LoadTextureFont > TTF_RenderText_Solid ", SDL_GetError());

    _texture = SDL_CreateTextureFromSurface(renderer, textSurface);

    SDL_FreeSurface(textSurface);
}

void TextureComponent::RemoveTexture()
{
    if (_texture != NULL)
        SDL_DestroyTexture(_texture);
}
