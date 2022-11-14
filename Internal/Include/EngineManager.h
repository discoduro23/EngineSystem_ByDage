#pragma once

#include "Singleton.h"
#include "SDL.h"

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

	// Load media
	bool LoadMedia(); //Check

	// Free media and shut down SDL
	void Close();
	
	/*****************************************************************************/

};

}