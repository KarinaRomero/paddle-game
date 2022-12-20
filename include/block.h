#ifndef BLOCK_H_
#define BLOCK_H_

#include "vector"
#include "game_object.h"

class Block : public GameObject
{
private:
    // Colors configured
    const std::vector<SDL_Color> _colors = {{18, 44, 184}, {80, 88, 133}, {47, 175, 235}, {237, 159, 107}, {184, 60, 18}};
    // Rates of the colors
    const std::vector<int> _rates = {9, 10, 15, 22, 44};
    // Value in points 
    const std::vector<int> _pointValues = {600, 550, 250, 150, 100};
    
    // Current points for this block
    int _points = 0;

    // current color selected
    int _currentColorSelected;
    Uint8 r;
    Uint8 g;
    Uint8 b;
    Uint8 alpha = 0xFF;
    
    // Draw the shape
    void DrawRectShape(SDL_Renderer *renderer);
    
public:
    // Default constructor
    Block();
    // Custom constructor
    Block(Utilities::Vector2D position, std::string tag);
    // Rule of five copy constructor
    Block(const Block &block);
    // Rule of five copy assignment
    Block &operator=(const Block &block);
    //Rule of five move constructor
    Block(Block&& block);
    // Rule of five move assignment
    Block& operator=(Block&& block);
    // Rule of five destructor
    ~Block() override;
    
    // Overwrite the function of the parent GameObject
    void Draw(SDL_Renderer* renderer) override;
    void Update() override;
    void CollisionDetected(GameObject* other) override;

    // Get and Set
    int GetPoints(){return _points;};
};
#endif