#include "Platform.h"

void Platform::move()
{
	//move down affected by speed
	mPosY += mVelY * TimeManager::GetInstancePtr()->GetDeltaTime();
	
}

void Platform::Update()
{
	move();
}
