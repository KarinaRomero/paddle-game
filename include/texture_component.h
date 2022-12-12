
#ifndef TEXTURE_COMPONENT_H
#define TEXTURE_COMPONENT_H

#include <string>
#include "SDL2/SDL.h"
#include "utilities.h"

class TextureComponent
{
public:
    TextureComponent();
    ~TextureComponent();
    void RemoveTexture();

    void LoadTexture(std::string path, SDL_Renderer * worldRenderer, SDL_Surface* worldSurface);
    void Draw(SDL_Renderer* renderer, Utilities::Vector2D position, Utilities::Vector2D size);

private:
    SDL_Texture *_texture;
    SDL_Surface* GenerateSurface(std::string path, SDL_Surface* worldSurface);
};
#endif
