#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "texture_component.h"
#include "utilities.h"

class GameObject
{
private:
    // The texture for this GameObject
    TextureComponent *_textureComponent;

protected:
    // Path of the texture
    std::string _path;
    // General values for the game object
    Utilities::Vector2D _size = {0, 0};
    Utilities::Vector2D _velocity = {0, 0};
    Utilities::Vector2D _position = {0, 0};
    Utilities::Vector2D _initialPosition = {0, 0};
    SDL_Rect _boxCollision = {0, 0, 0, 0};
    // The tag or name for the GameObject
    std::string _tag = "";

public:
    // Constructors and destructor
    GameObject();
    GameObject(std::string path, Utilities::Vector2D position);
    virtual ~GameObject() = default;
    // Initialize the GameObject
    void Initialize(SDL_Renderer *worldRenderer, SDL_Surface *worldSurface);
    void Initialize(std::string displayText, SDL_Renderer *worldRenderer, SDL_Surface *worldSurface, SDL_Color color);

    // Get and Set
    void SetTag(std::string tagValue) { _tag = tagValue; };
    std::string GetTag(){return _tag;};
    Utilities::Vector2D GetSize() { return _size; };
    void SetSize(Utilities::Vector2D size) { _size = size; };
    Utilities::Vector2D GetPosition() { return _position; };
    void SetPosition(Utilities::Vector2D position) { _position = position; };
    SDL_Rect GetBoxCollision() { return _boxCollision; };

    // Methods
    void Reset();
    void CollisionDetected(GameObject* other);
    void Update();
    void Draw(SDL_Renderer *renderer);
    void Draw(SDL_Renderer *renderer, std::string displayText, SDL_Color color);
    void Clean();
};

#endif