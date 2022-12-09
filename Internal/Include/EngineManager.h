#pragma once

#include "Singleton.h"
#include "SDL.h"
#include <SDL_image.h>
#include <stdio.h>
#include <string>

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

	// Private constructor to avoid more than one instance
	EngineManager() {};

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
	
	// Destroy Engine
	void Destroy();

	// Shut down SDL
	void Close();
	
	/*****************************************************************************/

};