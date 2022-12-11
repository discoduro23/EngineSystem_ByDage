#include "SoundManager.h"

bool SoundManager::Init()
{
	//Initialize SDL_mixer
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
		return false;
	}
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		return false;
	}
	
	return true;
	
}

void SoundManager::Destroy()
{
	// Liberar diccionario mMusic
	for (std::map<std::string, Mix_Music*>::iterator it = mMusic.begin(); it != mMusic.end(); ++it)
	{
		Mix_FreeMusic(it->second);
	}
	
	// Liberar diccionario mSounds
	for (std::map<std::string, Mix_Chunk*>::iterator it = mSounds.begin(); it != mSounds.end(); ++it)
	{
		Mix_FreeChunk(it->second);
	}
}

void SoundManager::PlayASound(int channel, std::string name, int loops)
{
	Mix_PlayChannel(channel, mSounds[name], loops);
}


void SoundManager::PlayMusic(std::string name, int loops)
{
	Mix_PlayMusic(mMusic[name], loops);
}

void SoundManager::LoadSound(std::string path, std::string name)
{
	//The sound that will be loaded
	Mix_Chunk* sound = NULL;

	//Load sound
	sound = Mix_LoadWAV(path.c_str());
	if (sound == NULL)
	{
		printf("Failed to load sound effect! SDL_mixer Error: %s\n", Mix_GetError());
	}
	mSounds[name] = sound;
}

void SoundManager::LoadMusic(std::string path, std::string name)
{
	//The music that will be loaded
	Mix_Music* music = NULL;
	
	//Load music
	music = Mix_LoadMUS(path.c_str());
	if (music == NULL)
	{
		printf("Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
	}
	mMusic[name] = music;
}
