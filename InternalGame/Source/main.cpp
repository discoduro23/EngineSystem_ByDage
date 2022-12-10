/*This source code copyrighted by Lazy Foo' Productions (2004-2022)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings
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
	EngineManager::GetInstance().Init();
	
	//Create Game Manager
	GameManager gaM = GameManager("GameManager");
	ObjectManager::GetInstance().AddObject(&gaM);	

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

		EngineManager::GetInstance().PreUpdate();
	 	EngineManager::GetInstance().Update();
		EngineManager::GetInstance().PostUpdate();
		
	}

	EngineManager::GetInstance().Destroy();
	EngineManager::GetInstance().Close();
	EngineManager::GetInstance().DestroySingleton();


	return 0;
	
//movido a gamemanager
	/*//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{	
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//The dot that will be moving around on the screen
			Dot dot1(20,20);
			Dot dot2(60,60);
			Dot dot3(100, 100);

			//While application is running
			while( !quit )
			{
				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
					
				}
				
				
				//Move the dot
				dot1.move(0);
				dot2.move(1);
				dot3.move(2);

				//Clear screen
				SDL_SetRenderDrawColor( mRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear( gRenderer );

				//Render objects
				dot1.render(0);
				dot2.render(1);
				dot3.render(2);
				
				//Update screen
				SDL_RenderPresent( gRenderer );
			}
		}
	}
	
	//Free resources and close SDL
	close();

	//Destroy Input Manager system
	InputManager::DestroySingleton();
	*/
	return 0;
}