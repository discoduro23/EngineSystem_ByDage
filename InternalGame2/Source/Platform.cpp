#include "Platform.h"

void Platform::move()
{
	//move down affected by speed
	mPosY += mVelY * TimeManager::GetInstancePtr()->GetDeltaTime();
	
	//reset y position randomly if it goes off screen
	if (mPosY > GraphicManager::GetInstancePtr()->GetHeight())
	{
		mPosY = -mHeight;
		mPosX = rand() % (GraphicManager::GetInstancePtr()->GetWidth() - mWidth);
		if (rand() % 5 == 0) {
			canMove = true;
			if (rand() % 2 == 0)
				direction = -1;
			else
				direction = 1;
		}
			
	}
}

void Platform::Update()
{
	move();
	if (canMove)
	{
		if (direction <= 0) {
			mPosX -= mVelX * TimeManager::GetInstancePtr()->GetDeltaTime();
			if (mPosX < 0)
				direction = 1;
		}
		else if (direction > 0)
		{
			mPosX += mVelX * TimeManager::GetInstancePtr()->GetDeltaTime();
			if (mPosX > GraphicManager::GetInstancePtr()->GetWidth() - mWidth)
				direction = -1;
		}
		
	}
}
