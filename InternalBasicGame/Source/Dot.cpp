#include "Dot.h"

void Dot::move(int moveMode)
{
	//Reset velocity
	mVelX = 0;
	mVelY = 0;
	
	switch (moveMode)
	{
	case 0:
		if (InputManager::GetInstance().GetKey(SDL_SCANCODE_UP)) mVelY -= velMax;
		if (InputManager::GetInstance().GetKey(SDL_SCANCODE_DOWN)) mVelY += velMax;
		if (InputManager::GetInstance().GetKey(SDL_SCANCODE_LEFT)) mVelX -= velMax;
		if (InputManager::GetInstance().GetKey(SDL_SCANCODE_RIGHT)) mVelX += velMax;
		break;
		
	case 1:
		if (InputManager::GetInstance().GetKey(SDL_SCANCODE_W)) mVelY -= velMax;
		if (InputManager::GetInstance().GetKey(SDL_SCANCODE_S)) mVelY += velMax;
		if (InputManager::GetInstance().GetKey(SDL_SCANCODE_A)) mVelX -= velMax;
		if (InputManager::GetInstance().GetKey(SDL_SCANCODE_D)) mVelX += velMax;
		break;
		
	case 2:
		//Give random number between 0 and 3 (For random "AI")
		int random = rand() % 4;
		switch (random)
		{
		case 0:
			mVelY -= velMax;
			break;
		case 1:
			mVelY += velMax;
			break;
		case 2:
			mVelX -= velMax;
			break;
		case 3:
			mVelX += velMax;
			break;
		default:
			break;
		}
	}
	
		//Move the dot left or right
		mPosX += mVelX;
		//Move the dot up or down
		mPosY += mVelY;
		
			//If the dot went too far to the left or right
		if (((mPosX < 0) || (mPosX + mWidth > GraphicManager::GetInstance().GetWidth()) )&& !collision)
		{
			//Move back
			mPosX -= mVelX;
		}

		//If the dot went too far up or down
		if (((mPosY < 0) || (mPosY + mHeight > GraphicManager::GetInstance().GetHeight()) )&& !collision)
		{
			//Move back
			mPosY -= mVelY;
		}
		
}

void Dot::Update()
{
	move(moveMode);
}
