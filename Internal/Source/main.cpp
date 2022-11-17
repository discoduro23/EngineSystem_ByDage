/*This source code copyrighted by Lazy Foo' Productions (2004-2022)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

#include "InputManager.h"
#include <iostream>


//The application time based timer
class LTimer
{
    public:
		//Initializes variables
		LTimer();

		//The various clock actions
		void start();
		void stop();
		void pause();
		void unpause();

		//Gets the timer's time
		Uint32 getTicks();

		//Checks the status of the timer
		bool isStarted();
		bool isPaused();

    private:
		//The clock time when the timer started
		Uint32 mStartTicks;

		//The ticks stored when the timer was paused
		Uint32 mPausedTicks;

		//The timer status
		bool mPaused;
		bool mStarted;
};

//The dot that will move around on the screen
class Dot
{
    public:
		//The dimensions of the dot
		static const int DOT_WIDTH = 20;
		static const int DOT_HEIGHT = 20;

		//Maximum axis velocity of the dot
		static const int DOT_VEL = 10;

		//Initializes the variables
		Dot(int x = 0, int y = 0);

		//Takes key presses and adjusts the dot's velocity
		void handleEvent( SDL_Event& e );

		//Moves the dot
		void move(int moveMode = 0);

		//Shows the dot on the screen
		void render(int colorStyle = 0);
		
    private:
		//The X and Y offsets of the dot
		int mPosX, mPosY;

		//The velocity of the dot
		int mVelX, mVelY;
};

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();


//Scene textures
LTexture gDotTexture;
LTexture gDotTexture1;
LTexture gDotTexture2;


void Dot::move(int moveMode)
{
	//Reset velocity
	mVelX = 0;
	mVelY = 0;

	//Get key press (https://wiki.libsdl.org/SDL_Scancode)
	
	switch (moveMode)
	{
	case 0:
		if (InputManager::GetInstance().GetKey(SDL_SCANCODE_UP)) mVelY -= DOT_VEL;
		if (InputManager::GetInstance().GetKey(SDL_SCANCODE_DOWN)) mVelY += DOT_VEL;
		if (InputManager::GetInstance().GetKey(SDL_SCANCODE_LEFT)) mVelX -= DOT_VEL;
		if (InputManager::GetInstance().GetKey(SDL_SCANCODE_RIGHT)) mVelX += DOT_VEL;
		break;
	case 1:
		if (InputManager::GetInstance().GetKey(SDL_SCANCODE_W)) mVelY -= DOT_VEL;
		if (InputManager::GetInstance().GetKey(SDL_SCANCODE_S)) mVelY += DOT_VEL;
		if (InputManager::GetInstance().GetKey(SDL_SCANCODE_A)) mVelX -= DOT_VEL;
		if (InputManager::GetInstance().GetKey(SDL_SCANCODE_D)) mVelX += DOT_VEL;
		break;
	case 2:
		//Give random number between 0 and 3 (For random "AI")
		int random = rand() % 4;
		switch (random)
		{
		case 0:
			mVelY -= DOT_VEL;
			break;
		case 1:
			mVelY += DOT_VEL;
			break;
		case 2:
			mVelX -= DOT_VEL;
			break;
		case 3:
			mVelX += DOT_VEL;
			break;
		default:
			break;
		}
	}
	
	
    //Move the dot left or right
    mPosX += mVelX;

    //If the dot went too far to the left or right
    if( ( mPosX < 0 ) || ( mPosX + DOT_WIDTH > SCREEN_WIDTH ) )
    {
        //Move back
        mPosX -= mVelX;
    }

    //Move the dot up or down
    mPosY += mVelY;

    //If the dot went too far up or down
    if( ( mPosY < 0 ) || ( mPosY + DOT_HEIGHT > SCREEN_HEIGHT ) )
    {
        //Move back
        mPosY -= mVelY;
    }
}

void Dot::render(int colorSelection)
{
    //Show the dot
	switch (colorSelection) {
	case 0:
		gDotTexture1.render(mPosX, mPosY);
		break;
	case 1:
		gDotTexture2.render(mPosX, mPosY);
		break;
	case 2:
		gDotTexture.render(mPosX, mPosY);
		break;
	default:
		break;
	}
	
}

Dot::Dot(int x, int y)
{
	//Initialize the offsets
	mPosX = x;
	mPosY = y;

	//Initialize the velocity
	mVelX = 0;
	mVelY = 0;
}



bool loadMedia()
{
	//Loading success flag
	bool success = false;
	
	
	
	//Load dot texture
	if (!gDotTexture1.loadFromFile(routeArrowsRelease)) printf("Failed to load dot texture for the ARROWS!\n");
	else if (!gDotTexture2.loadFromFile(routeWASDRelease)) printf("Failed to load dot texture for the WASD!\n");
	else if (!gDotTexture.loadFromFile(routeDefultRelease)) printf("Failed to load dot texture for the Default!\n");
	else success = true;
	

	//Second check for debug exe
	if (!success) {
		if (!gDotTexture1.loadFromFile(routeArrowsDebug)) printf("Failed to load dot texture for the ARROWS!\n");
		else if (!gDotTexture2.loadFromFile(routeWASDDebug)) printf("Failed to load dot texture for the WASD!\n");
		else if (!gDotTexture.loadFromFile(routeDefultDebug)) printf("Failed to load dot texture for the Default!\n");
		else success = true;
	}

	return success;
}

void close()
{
	//Free loaded images
	gDotTexture1.free();
	gDotTexture2.free();
	gDotTexture.free();

	//Destroy window	
	

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

int main( int argc, char* args[] )
{
	//Create Input Manager Singleton
	InputManager::CreateSingleton();

	//Update the input system
	InputManager::GetInstance().Update();
	
	
	//Start up SDL and create window
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
	
	return 0;
}