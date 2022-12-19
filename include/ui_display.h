#ifndef SCORE_H_
#define SCORE_H_

#include "game_object.h"

class UIDisplay : public GameObject
{
public:
    // Constructors and destructor
    UIDisplay(std::string path, Utilities::Vector2D position, Utilities::Vector2D size);
    ~UIDisplay();

    // Get and Set
    SDL_Color GetColor() { return _color; };
    void SetText(std::string displayText){ _currentText = displayText;};
    std::string GetText(){return _currentText;};

private:
    // Const value for the color
    const SDL_Color _color = {184, 144, 18};
    // The current text to show
    std::string _currentText = "";
};

#endif