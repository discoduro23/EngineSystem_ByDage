#pragma once

#include "SDL.h"
#include "Singleton.h"
#include <stdio.h>
#include <string>
#include <SDL_mixer.h>
#include <map>

/**
Sound Manager class
*/

class SoundManager :public Singleton<SoundManager> {
	/*****************************************************************************/
	friend class Singleton<SoundManager>;
	/*****************************************************************************/
	
private:

	// Private constructor to avoid more than one instance
	SoundManager() {};

	// array of sounds
	std::map<std::string, Mix_Chunk*> mSounds;
	// array of music
	std::map<std::string, Mix_Music*> mMusic;
	/*****************************************************************************/
	
public:
	
	// Initialize the sound manager
	bool Init();

	// Destroy the sound manager
	void Destroy();

	// Play a sound
	void PlaySound(int channel, std::string name, int loops = 0);

	// Play a music
	void PlayMusic(std::string name, int loops = 0);

	// Load a sound
	void LoadSound(std::string, std::string);
	
	// Load a music
	void LoadMusic(std::string, std::string);

	//Is playing sound
	bool IsPlayingSound(std::string, int channel) { return Mix_Playing(channel); }

	//Is playing music
	bool IsPlayingMusic(std::string) { return Mix_PlayingMusic(); }

	//Stop sound
	void StopSound(std::string, int channel) { Mix_HaltChannel(channel); }

	//Stop music
	void StopMusic(std::string) { Mix_HaltMusic(); }
	
	//Pause sound
	void PauseSound(std::string, int channel) { Mix_Pause(channel); }
	
	//Pause music
	void PauseMusic(std::string) { Mix_PauseMusic(); }
	
	//Resume sound
	void ResumeSound(std::string, int channel) { Mix_Resume(channel); }
	
	//Resume music
	void ResumeMusic(std::string) { Mix_ResumeMusic(); }

	//Set sound volume
	void SetSoundVolume(std::string, int channel, int volume) { Mix_Volume(channel, volume); }
	
	//Set music volume
	void SetMusicVolume(std::string, int volume) { Mix_VolumeMusic(volume); }

	
	/*****************************************************************************/

};
