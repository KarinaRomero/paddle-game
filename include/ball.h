#ifndef BALL_H
#define BALL_H

#include "game_object.h"
#include <string>

class Ball : public GameObject
{
public:
    // Constructors and destructor
    Ball();
    Ball(std::string path, Utilities::Vector2D position, Utilities::Vector2D min, Utilities::Vector2D max);
    ~Ball() override;
    
    // Overwrite methods for the GameObject class
    void Update() override;
    void CollisionDetected(GameObject* other) override;
    void Reset() override;

    // Get and Set
    int GetScore(){return _score;};
    
private:
    // Limits the ball on the screen
    Utilities::Vector2D _moveLimitsMax;
    Utilities::Vector2D _moveLimitsMin;
    // Current score
    int _score = 0;
    // Number of faults
    int _faults = 0;
    // The value for an fault
    const int _faultValue = 200;
};

#endif