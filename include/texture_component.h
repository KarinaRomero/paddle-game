
#ifndef TEXTURE_COMPONENT_H
#define TEXTURE_COMPONENT_H

#include <string>
#include "SDL2/SDL.h"
#include "SDL_ttf.h"
#include "utilities.h"

class TextureComponent
{
public:
    TextureComponent();
    ~TextureComponent();
    void RemoveTexture();
    void LoadTextureFont(std::string path, std::string displayText, SDL_Renderer *worldRenderer, SDL_Surface *worldSurface, SDL_Color color);
    void SetTextureText(SDL_Renderer* renderer, std::string displayText, SDL_Color color);
    void LoadTexture(std::string path, SDL_Renderer * worldRenderer, SDL_Surface* worldSurface);
    void Draw(SDL_Renderer* renderer, Utilities::Vector2D position, Utilities::Vector2D size);
    void Draw(SDL_Renderer* renderer, Utilities::Vector2D position, Utilities::Vector2D size, std::string displayText, SDL_Color color);

private:
    SDL_Texture* _texture;
    TTF_Font* _font;
    SDL_Surface* GenerateSurface(std::string path, SDL_Surface* worldSurface);
};
#endif
