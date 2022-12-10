#include "Knight.h"

void Knight::move(int moveMode)
{
	//Reset velocity
	mVelX = 0;
	mVelY = 0;


	if (InputManager::GetInstance().GetKey(SDL_SCANCODE_UP)) mVelY -= velMax;
	if (InputManager::GetInstance().GetKey(SDL_SCANCODE_DOWN)) mVelY += velMax;
	if (InputManager::GetInstance().GetKey(SDL_SCANCODE_LEFT)) mVelX -= velMax;
	if (InputManager::GetInstance().GetKey(SDL_SCANCODE_RIGHT)) mVelX += velMax;



	//Move the Knight left or right
	mPosX += mVelX;
	//Move the Knight up or down
	mPosY += mVelY;


	//If the Knight went too far to the left or right
	if ((mPosX < 0) || (mPosX + mWidth > GraphicManager::GetInstance().GetWidth()))
	{
		//Move back
		mPosX -= mVelX;
	}

	//If the Knight went too far up or down
	if ((mPosY < 0) || (mPosY + mHeight > GraphicManager::GetInstance().GetHeight()))
	{
		//Move back
		mPosY -= mVelY;
	}

}

void Knight::Update()
{
	move(moveMode);
}