
#ifndef TEXTURE_COMPONENT_H
#define TEXTURE_COMPONENT_H

#include <string>
#include "SDL2/SDL.h"

class TextureComponent
{
public:
    TextureComponent();
    ~TextureComponent();

    void LoadTexture(std::string path, SDL_Renderer * worldRenderer, SDL_Surface* worldSurface);
    SDL_Texture *_texture;

private:
    //SDL_Texture *_texture;
    // Methods
    SDL_Surface* GenerateSurface(std::string path, SDL_Surface* worldSurface);
};
#endif
