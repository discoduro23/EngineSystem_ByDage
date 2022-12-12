#include "EngineManager.h"

int PostUpdateThread(void* data);

bool EngineManager::Init()
{
	//Create Engine
	TimeManager::CreateSingleton();
	InputManager::CreateSingleton();
	SoundManager::CreateSingleton();
	ObjectManager::CreateSingleton();
	GraphicManager::CreateSingleton();
	SaveManager::CreateSingleton();

	//Initialize Engine
	if (!GraphicManager::GetInstance().Init(width,height))
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
	SDL_WaitThread(GraphicalThread, nullptr);
	GraphicManager::GetInstance().Destroy();
	GraphicManager::DestroySingleton();
	
	ObjectManager::GetInstance().Destroy();
	ObjectManager::DestroySingleton();
	
	SaveManager::DestroySingleton();

	SoundManager::GetInstance().Destroy();
	InputManager::DestroySingleton();
	TimeManager::DestroySingleton();
	
	
}


void EngineManager::Close() {
	// Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}


//threads
void EngineManager::MuxUpdate() {
	
	PreUpdate();
	Update();
	//cout << "Update Thread\n";
	
	TimeManager* tM = TimeManager::GetInstancePtr();	
	if (tM->GetFPStimer() > 1.0f){
		tM->ResetFPStimer();
		tM->CalculateFPS();
	}

	if (thread_signal != 1)
	{
		thread_signal = 1;
		SDL_Thread* GraphicalThread = CreateThread(PostUpdateThread, "Graphic", (void*)gData);
		if (tM->GetFPStimer() <= 1.0f){
			tM->SumFPS();
		}
	}
}

SDL_Thread* EngineManager::CreateThread(SDL_ThreadFunction func, const char* name, void* data)
{
	return SDL_CreateThread(func, name, data);
}

int PostUpdateThread( void* data) {
	EngineManager::GetInstance().PostUpdate();
	//cout << "Graphic Thread\n";

	
	
	thread_signal = 0;
	return 0;
}