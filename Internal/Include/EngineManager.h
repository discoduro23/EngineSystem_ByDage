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
#include "SaveManager.h"

static int thread_signal = 0;

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
	SDL_sem* gDataLock = nullptr;

	//The "data buffer"
	int gData = -1;
	int hData = -2;

	
	SDL_Thread* GraphicalThread = nullptr;


	/*****************************************************************************/

public:

	// Initialize Engine
	bool Init();

	/*********************************/

	//Insert in main only one version, the PreUpdate, Update, PostUpdate for one thread execution or the MuxUpdate for multithread execution
	 
	//PreUpdate Engine
	void PreUpdate();
	
	//Update Engine
	void Update();
	
	//PostUpdate Engine
	void PostUpdate();

	//Multithread Update all in one
	void MuxUpdate();
	
	/*********************************/


	//Set Window Size
	void SetWindowSize(int lWidth, int lHeight) { width = lWidth; height = lHeight; }

	void SetCursorToStart();
	
	void HideCursor();
	
	// Destroy Engine
	void Destroy();

	// Shut down SDL
	void Close();
		
	//create thread
	SDL_Thread* CreateThread(SDL_ThreadFunction func, const char* name, void* data);
	/*****************************************************************************/

};