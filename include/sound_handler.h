#ifndef SOUND_HANDLER_H
#define SOUND_HANDLER_H

#include "vector"
#include "string"
#include "SDL_mixer.h"

enum Sound_effect
{
    BALL,
    BLOCK
};

class SoundHandler
{
public:
    SoundHandler();
    ~SoundHandler();
    void Initialize();
    void PlayMusic();
    void PlaySoundEffect(Sound_effect soundEffect);
    void Clean();

private:
    const std::string _musicPath = "../resources/VGMAChallenge-July6th.wav";
    const std::string _ballPath = "../resources/ball.wav";
    const std::string _blockPath = "../resources/block.wav";

    const int defaultVolume = 16;
    const int defaultChannel = -1;

    Mix_Music *_backgroundMusic;
    Mix_Chunk *_ball;
    Mix_Chunk *_block;
};

#endif