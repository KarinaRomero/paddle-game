#include "sound_handler.h"
#include "logger.h"

SoundHandler::SoundHandler()
{
    _backgroundMusic = NULL;
    _ball = NULL;
    _block = NULL;
}

void SoundHandler::Initialize()
{
    _backgroundMusic = Mix_LoadMUS(_musicPath.c_str());

    if (_backgroundMusic == NULL)
    {
        Logger::LogLibraryError("SoundHandler::SoundHandler ", Mix_GetError());
    }
    else
        PlayMusic();

    _ball = Mix_LoadWAV(_ballPath.c_str());
    if (_ball == NULL)
    {
        Logger::LogLibraryError("SoundHandler::SoundHandler ", Mix_GetError());
    }

    _block = Mix_LoadWAV(_blockPath.c_str());
    if (_block == NULL)
    {
        Logger::LogLibraryError("SoundHandler::SoundHandler ", Mix_GetError());
    }
}

SoundHandler::~SoundHandler()
{
    if (_backgroundMusic != NULL)
        Mix_FreeMusic(_backgroundMusic);
    if (_ball)
        Mix_FreeChunk(_ball);
    if (_block)
        Mix_FreeChunk(_block);

    _backgroundMusic = NULL;
    _ball = NULL;
    _block = NULL;
}

void SoundHandler::PlayMusic()
{
    Mix_PlayMusic(_backgroundMusic, -1);
    Mix_VolumeMusic(defaultVolume);
}

void SoundHandler::PlaySoundEffect(Sound_effect soundEffect)
{
    switch (soundEffect)
    {
    case Sound_effect::BALL:
        Mix_PlayChannel(-1, _ball, 0);
        break;
    case Sound_effect::BLOCK:
        Mix_PlayChannel(-1, _block, 0);
        break;
    default:
        break;
    }
}
