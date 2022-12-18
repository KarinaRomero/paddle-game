#ifndef SCORE_H_
#define SCORE_H_

#include "game_object.h"

class UIDisplay : public GameObject
{
public:
    UIDisplay(std::string path, Utilities::Vector2D position, Utilities::Vector2D size);
    ~UIDisplay();
    SDL_Color GetColor() { return _color; };
    void SetText(std::string displayText){ _currentText = displayText;};
    std::string GetText(){return _currentText;};

private:
    SDL_Color _color = {184, 144, 18};
    std::string _currentText = "";
};

#endif