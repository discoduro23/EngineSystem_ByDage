//BASIC GAME

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

#include "EngineManager.h"
#include "ObjectManager.h"
#include "InputManager.h"
#include "GameManager.h"

#include <iostream>



int main(int argc, char* args[])
{
	//Start the machine
	EngineManager::CreateSingleton();
	EngineManager* eM = EngineManager::GetInstancePtr();
	
	eM->SetWindowSize(1280, 720);
	eM->Init();

	//Create Game Manager
	GameManager* gaM = new GameManager("GameManager");
	ObjectManager::GetInstance().AddObject(gaM);

	//The while
	bool quit = false;
	SDL_Event e;
	eM->HideCursor();
	//While application is running
	while (!quit)
	{
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}

		}
		eM->MuxUpdate();			//Separate update
		eM->SetCursorToStart();

		/*eM->PreUpdate();			*
		eM->Update();				* Update without threads
		eM->PostUpdate();			*/
	}

	eM->Destroy();
	eM->Close();
	EngineManager::DestroySingleton();

	return 0;
}