#include "EngineManager.h"

bool EngineManager::Init()
{
	//Create Engine
	GraphicManager::CreateSingleton();
	InputManager::CreateSingleton();
	TimeManager::CreateSingleton();
	ObjectManager::CreateSingleton();
	
	//Initialize Engine
	if (!GraphicManager::GetInstance().Init())
	{
		printf("Failed to initialize Graphics!\n");
		return false;
	}
	else
	{
		return true;
	}
	
	return false;
}

void EngineManager::PreUpdate()
{
	TimeManager::GetInstance().Update();
	InputManager::GetInstance().Update();
}

void EngineManager::Update()
{
	ObjectManager::GetInstance().Update();
}

void EngineManager::PostUpdate()
{
	GraphicManager::GetInstance().Update();
}

void EngineManager::Destroy()
{
	//Destroy Engine
	GraphicManager::GetInstance().Destroy();
	GraphicManager::GetInstance().DestroySingleton();
	
	InputManager::GetInstance().DestroySingleton();
	TimeManager::GetInstance().DestroySingleton();
	
	ObjectManager::GetInstance().Destroy();
	ObjectManager::GetInstance().DestroySingleton();
}


void EngineManager::Close() {
	// Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}
