#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

#include "EngineManager.h"
#include "ObjectManager.h"
#include "InputManager.h"
#include "GameManager.h"

#include <iostream>



int main( int argc, char* args[] )
{	
	
	//Start the machine
	EngineManager::CreateSingleton();
	EngineManager* eM = EngineManager::GetInstancePtr();

	eM->SetWindowSize(512, 480);
	eM->Init();

	//Change the window name
	eM->SetWindowTitleFromPath(args[0]);

	//Create Game Manager
	GameManager* gaM = new GameManager("GameManager");
	ObjectManager::GetInstance().AddObject(gaM);

	//The while
	bool quit = false;
	SDL_Event e;
	
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
		eM->GetInstance().MuxUpdate();
		
	}

	eM->GetInstance().Destroy();
	eM->GetInstance().Close();
	eM->GetInstance().DestroySingleton();
	
	return 0;
}