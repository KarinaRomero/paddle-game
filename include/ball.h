#include "game-object.h"
#include <string>

class Ball : public GameObject
{
public:
    
    Ball();
    ~Ball();
    
    void Update();
    void Clean();
private:
};
