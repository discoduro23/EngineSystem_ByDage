#include "Knight.h"

void Knight::move()
{
	//Reset velocity
	mVelX = 0;
	mVelY = 0;

	if (InputManager::GetInstance().GetKey(SDL_SCANCODE_W)) mVelY -= velMax;
	if (InputManager::GetInstance().GetKey(SDL_SCANCODE_S)) mVelY += velMax;
	if (InputManager::GetInstance().GetKey(SDL_SCANCODE_A)) mVelX -= velMax;
	if (InputManager::GetInstance().GetKey(SDL_SCANCODE_D)) mVelX += velMax;

	//Move the Knight left or right
	mPosX += mVelX * TimeManager::GetInstance().GetDeltaTime();
	//Move the Knight up or down
	mPosY += mVelY * TimeManager::GetInstance().GetDeltaTime();


	//If the Knight went too far to the left or right
	if ((mPosX < 0) || (mPosX + mWidth > GraphicManager::GetInstance().GetWidth()))
	{
		//Move back
		mPosX -= mVelX * TimeManager::GetInstance().GetDeltaTime();
	}

	//If the Knight went too far up or down
	if ((mPosY < 0) || (mPosY + mHeight > GraphicManager::GetInstance().GetHeight()))
	{
		//Move back
		mPosY -= mVelY * TimeManager::GetInstance().GetDeltaTime();
	}

}

void Knight::Update()
{
	move();
	if (isInit) ChronoID = TimeManager::GetInstance().StartChrono();

	if ((int)(TimeManager::GetInstance().GetChrono(ChronoID) * 10) % 3 == 0) SetTexture("Paso1");
	else SetTexture("Paso2");
}