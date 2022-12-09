#include "EngineManager.h"

bool EngineManager::Init()
{
	//Create Engine
	TimeManager::CreateSingleton();
	InputManager::CreateSingleton();
	SoundManager::CreateSingleton();
	ObjectManager::CreateSingleton();
	GraphicManager::CreateSingleton();

	//Initialize Engine
	if (!GraphicManager::GetInstance().Init())
	{
		printf("Failed to initialize Graphics!\n");
		return false;
	}
	else if (!TimeManager::GetInstance().Init())
	{
		printf("Failed to initialize Time!\n");
		return false;
	}
	else if (!SoundManager::GetInstance().Init())
	{
		printf("Failed to initialize Sound!\n");
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
	ObjectManager::GetInstance().Destroy();
	ObjectManager::GetInstance().DestroySingleton();
	SoundManager::GetInstance().Destroy();
	InputManager::GetInstance().DestroySingleton();
	TimeManager::GetInstance().DestroySingleton();
	
	
}


void EngineManager::Close() {
	// Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}
