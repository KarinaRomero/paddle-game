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
    // Constructors and destructor
    SoundHandler();
    ~SoundHandler();
    // Methods
    void Initialize();
    void PlayMusic();
    void PlaySoundEffect(Sound_effect soundEffect);

private:
    // Constant paths where the audio tracks are stored
    const std::string _musicPath = "../resources/VGMAChallenge-July6th.wav";
    const std::string _ballPath = "../resources/ball.wav";
    const std::string _blockPath = "../resources/block.wav";

    // Default configurations to reproduce the track
    const int defaultVolume = 16;
    const int defaultChannel = -1;

    // Pointers to store the tracks
    Mix_Music *_backgroundMusic;
    Mix_Chunk *_ball;
    Mix_Chunk *_block;
};

#endif