#include <Player.h>

void Player::move()
{
	//move down affected by gravity
	if (mVelY < velMax)
		mVelY += gravity * TimeManager::GetInstancePtr()->GetDeltaTime();

	if (mVelY <= 0)
		SetTexture("Body2");
	else if (mVelY > 0)
		SetTexture("Body1");
	//move left and right affected by input
	if (InputManager::GetInstancePtr()->GetKey(SDL_SCANCODE_A))
	{
		if (mVelX > -velMax)
			mVelX -= 0.5f;
	}
	else if (InputManager::GetInstancePtr()->GetKey(SDL_SCANCODE_D))
	{
		if (mVelX < velMax)
			mVelX += 0.5f;
	}
	else
	{
		if (mVelX > 0)
			mVelX -= 0.5f;
		else if (mVelX < 0)
			mVelX += 0.5f;
	}
	
	//move up affected by input
	
	
	//set the position
	mPosX += mVelX * TimeManager::GetInstancePtr()->GetDeltaTime();
	float previousMPosY = mPosY;
	mPosY += mVelY * TimeManager::GetInstancePtr()->GetDeltaTime();

	if (mPosY <= GraphicManager::GetInstancePtr()->GetHeight() / 4)
	{
		isOnMaxHeight = true;
		mPosY = previousMPosY;
	}
	else {
		isOnMaxHeight = false;
	}
	
	//set the head position
	if (head != nullptr)
	{
		if (mVelY < 0)
			head->SetPosition(mPosX + 10, mPosY - 10);
		else if (mVelY > 0)
			head->SetPosition(mPosX + 7, mPosY - 9);
	}


	//testing--------------------------------------------------------------------------------
	//jump if below the ground
	if (mPosY > GraphicManager::GetInstancePtr()->GetHeight() - mHeight)
	{
		mVelY = -200;
	}
}

void Player::Update()
{
	move();
	
}
