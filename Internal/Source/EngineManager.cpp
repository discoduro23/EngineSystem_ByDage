#include "EngineManager.h"

bool EngineManager::Init()
{
	return false;
}

void EngineManager::Close() {
	// Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}
