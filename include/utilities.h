#ifndef UTILITIES_H_
#define UTILITIES_H_

#include "vector"
#include "SDL2/SDL.h"
#include "string"

#include <random>

namespace Utilities
{
    /*
     * This struct stores two float values
     */
    struct Vector2D
    {
        float x;
        float y;
    };
    // The const string where the best score is saved
    const std::string savePath{"../resources/save.txt"};
    /**
     * Checks if Two objects are colliding.
     *
     * This calculation only checks if the objects are colliding.
     *
     * @param objectA and SDL_Rect that provides the position and the size of the first shape.
     * @param objectB and SDL_Rect that provides the position and the size of the second shape.
     * @return true if the shapes are colliding, or false in the otherwise.
     */
    bool CheckCollision(SDL_Rect objectA, SDL_Rect objectB);
    /**
     * Calculate the distance.
     *
     * Calculate the distance between two objects.
     *
     * @param objectA and SDL_Rect that provides the position and the size of the first shape.
     * @param objectB and SDL_Rect that provides the position and the size of the second shape.
     * @return distance of `objects` in pixels de la window.
     */
    double Distance(SDL_Rect objectA, SDL_Rect objectB);
    /**
     * Generates an input value.
     *
     * With a 75% probability that object A will move on an axis toward object B.
     *
     * @param objectA and SDL_Rect that provides the position and the size of the first shape.
     * @param objectB and SDL_Rect that provides the position and the size of the second shape.
     * @return returns -1 y 1 if the object should move and 0 if not.
     */
    int BrainPaddleInputValue(SDL_Rect objectA, SDL_Rect objectB);
    /**
     * Reads the Best score.
     *
     * Read the save.txt file.
     *
     * @return returns the best score in the file or 0 if the file doesn't exist.
     */
    int ReadBestScore();
    /**
     * Saves the Best score.
     *
     * Save the best score in the save.txt file.
     *
     */
    void SaveBestScore(int score);
    /**
     * Generates an number.
     *
     * With a the rates generates a consecutive number,
     * regardless of length, the numbers in the vector must add up to 100%.
     *
     * @param rates it's a vector of the probabilities.
     * @return returns the number consecutive.
     */
    template <typename T>
    T RandomNumberByRates(std::vector<T> rates)
    {
        std::random_device randomDevice;
        std::mt19937 generator(randomDevice());
        std::uniform_int_distribution<int> distribution(0, 100);

        auto randomNumber = distribution(generator);
        auto counter = 0;
        auto rateAccumulated = 0;

        for (auto rate : rates)
        {
            rateAccumulated += rate;
            if (randomNumber <= rateAccumulated)
                return counter;
            else
                counter++;
        }
        return counter;
    }
}

#endif