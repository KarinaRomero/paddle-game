#include "window.h"

class Game
{
public:
    Game();
    ~Game();
    void Run();

private:
    // Variables
    Window* _window;
    // GameLoop
    void ProcessInput();
    void Update();
    void Render();

};
