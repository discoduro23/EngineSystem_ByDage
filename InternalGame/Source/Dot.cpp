#include "Dot.h"

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
	if ((mPosX < 0) || (mPosX + DOT_WIDTH > GraphicManager::GetInstance().GetWidth()))
	{
		//Move back
		mPosX -= mVelX;
	}

	//Move the dot up or down
	mPosY += mVelY;

	//If the dot went too far up or down
	if ((mPosY < 0) || (mPosY + DOT_HEIGHT > GraphicManager::GetInstance().GetHeight()))
	{
		//Move back
		mPosY -= mVelY;
	}
}

void Dot::Update()
{
	move(0);
}
