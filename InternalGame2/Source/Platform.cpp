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
	}
}

void Platform::Update()
{
	move();
}
