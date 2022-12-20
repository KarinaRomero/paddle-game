#ifndef PADDLE_H
#define PADDLE_H

#include "game_object.h"

class Paddle : public GameObject
{
public:
    // Constructors and destructor
    Paddle();
    Paddle(std::string path, Utilities::Vector2D position, Utilities::Vector2D moveMinMax);
    ~Paddle() override;
    
    // Constructors and destructor
    void SendInput(int input);
    void Update() override;
    void CollisionDetected(GameObject* other) override;
    
    // Get and set
    int GetState()const {return _currentState;};
    
private:
    Utilities::Vector2D _moveMinMax;
    int _currentState = 0;
};

#endif