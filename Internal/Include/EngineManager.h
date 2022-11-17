#pragma once

#include "Singleton.h"
#include "SDL.h"
#include <SDL_image.h>
#include <stdio.h>
#include <string>

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

	// Initialize SDL
	bool Init();
	
	// Free media and shut down SDL
	void Close();
	
	/*****************************************************************************/

};