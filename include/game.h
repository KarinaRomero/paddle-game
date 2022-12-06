#include "window.h"

class Game
{
public:
    Game();
    ~Game();
    void Run();

private:
    // Variables
    Window *_window;
    bool _isGameInitialized = false;

    // GameLoop
    void ProcessInput();
    void Update();
    void Render();
};
