#pragma once

#include "Singleton.h"
#include "SDL.h"
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <SDL_thread.h>

//Include all managers
#include "InputManager.h"
#include "TimeManager.h"
#include "ObjectManager.h"
#include "GraphicManager.h"
#include "SoundManager.h"

using namespace std;

/**
* Engine Manager class
*/

class EngineManager :public Singleton<EngineManager>
{
	/*****************************************************************************/
	friend class Singleton<EngineManager>;
	/*****************************************************************************/

private:

	int width = 640;
	int height = 480;

	// Private constructor to avoid more than one instance
	EngineManager() {};

	//Data access semaphore
	SDL_sem* gDataLock = NULL;

	//The "data buffer"
	int gData = -1;

	/*****************************************************************************/

public:

	// Initialize Engine
	bool Init();

	//PreUpdate Engine
	void PreUpdate();
	
	//Update Engine
	void Update();
	
	//PostUpdate Engine
	void PostUpdate();

	void MuxUpdate();
	
	//Set Window Size
	void SetWindowSize(int width, int height) { this->width = width; this->height = height; }
	
	// Destroy Engine
	void Destroy();

	// Shut down SDL
	void Close();
		
	//create thread
	SDL_Thread* CreateThread(SDL_ThreadFunction func, const char* name, void* data);
	/*****************************************************************************/

};