#ifndef PADDLE_H
#define PADDLE_H

#include "game_object.h"

class Paddle : public GameObject
{
public:
    Paddle();
    Paddle(std::string path, Utilities::Vector2D position, Utilities::Vector2D moveMinMax);
    ~Paddle();
    
    void SendInput(int input);
    void Update();
    int GetState(){return _currentState;};
    
private:
    Utilities::Vector2D _moveMinMax;
    int _currentState = 0;
};

#endif