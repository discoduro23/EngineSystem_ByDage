#include "Goblin.h"

void Goblin::move()
{
	//Reset velocity
	mVelX = 0;
	mVelY = 0;

	
    if (InputManager::GetInstance().GetKey(SDL_SCANCODE_W)) mVelY -= velMax;
    if (InputManager::GetInstance().GetKey(SDL_SCANCODE_S)) mVelY += velMax;
    if (InputManager::GetInstance().GetKey(SDL_SCANCODE_A)) mVelX -= velMax;
    if (InputManager::GetInstance().GetKey(SDL_SCANCODE_D)) mVelX += velMax;    

	//Move the Goblin left or right
	mPosX += mVelX * TimeManager::GetInstance().GetDeltaTime();
	//Move the Goblin up or down
	mPosY += mVelY * TimeManager::GetInstance().GetDeltaTime();


	//If the Goblin went too far to the left or right
	if ((mPosX < 0) || (mPosX + mWidth > GraphicManager::GetInstance().GetWidth()))
	{
		//Move back
		mPosX -= mVelX * TimeManager::GetInstance().GetDeltaTime();
	}

	//If the Goblin went too far up or down
	if ((mPosY < 0) || (mPosY + mHeight > GraphicManager::GetInstance().GetHeight()))
	{
		//Move back
		mPosY -= mVelY * TimeManager::GetInstance().GetDeltaTime();
	}

}

void Goblin::Update()
{
	move();
	if (isInit) ChronoID = TimeManager::GetInstance().StartChrono();

	if ((int)(TimeManager::GetInstance().GetChrono(ChronoID) * 10) % 3 == 0) SetTexture("paso1");
	else SetTexture("paso2");

}