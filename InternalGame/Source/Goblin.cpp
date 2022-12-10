#include "Goblin.h"

void Goblin::move(int moveMode)
{
	//Reset velocity
	mVelX = 0;
	mVelY = 0;

	
    if (InputManager::GetInstance().GetKey(SDL_SCANCODE_W)) mVelY -= velMax;
    if (InputManager::GetInstance().GetKey(SDL_SCANCODE_S)) mVelY += velMax;
    if (InputManager::GetInstance().GetKey(SDL_SCANCODE_A)) mVelX -= velMax;
    if (InputManager::GetInstance().GetKey(SDL_SCANCODE_D)) mVelX += velMax;    

	//Move the Goblin left or right
	mPosX += mVelX;
	//Move the Goblin up or down
	mPosY += mVelY;


	//If the Goblin went too far to the left or right
	if ((mPosX < 0) || (mPosX + mWidth > GraphicManager::GetInstance().GetWidth()))
	{
		//Move back
		mPosX -= mVelX;
	}

	//If the Goblin went too far up or down
	if ((mPosY < 0) || (mPosY + mHeight > GraphicManager::GetInstance().GetHeight()))
	{
		//Move back
		mPosY -= mVelY;
	}

}

void Goblin::Update()
{
	move(moveMode);
}