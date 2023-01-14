#include <Player.h>

void Player::Move()
{
	//move down affected by gravity
	if (mVelY < velMaxY)
		mVelY += gravity * TimeManager::GetInstancePtr()->GetDeltaTime();

	if (mVelY <= 0)
		SetTexture("Body2");
	else if (mVelY > 0)
		SetTexture("Body1");
	//move left and right affected by input
	if (InputManager::GetInstancePtr()->GetKey(SDL_SCANCODE_A))
	{
		if (mVelX > -velMaxX)
			mVelX -= 0.5f;
	}
	else if (InputManager::GetInstancePtr()->GetKey(SDL_SCANCODE_D))
	{
		if (mVelX < velMaxX)
			mVelX += 0.5f;
	}
	else
	{
		if (mVelX > 0)
			mVelX -= 0.5f;
		else if (mVelX < 0)
			mVelX += 0.5f;
	}
	
	//set the position
	mPosX += mVelX * TimeManager::GetInstancePtr()->GetDeltaTime();
	float previousMPosY = mPosY;
	mPosY += mVelY * TimeManager::GetInstancePtr()->GetDeltaTime();

	if (mPosY <= GraphicManager::GetInstancePtr()->GetHeight() / 4)
	{
		isOnMaxHeight = true;
		mPosY = previousMPosY;
	}
	else if (mVelY > 0){
		isOnMaxHeight = false;
	}

	//Appear on the other side of the screen
	if (mPosX + mWidth < 0)
		mPosX = GraphicManager::GetInstancePtr()->GetWidth();
	else if (mPosX > GraphicManager::GetInstancePtr()->GetWidth())
		mPosX = -mWidth;
	
	//set the head position
	if (head != nullptr)
	{
		if (mVelY < 0)
			head->SetPosition(mPosX + 10, mPosY - 10);
		else if (mVelY > 0)
			head->SetPosition(mPosX + 7, mPosY - 9);
	}
	
}

void Player::DeadMove()
{
	//Move sinusoidal in the X axis among the middle of the screen using the time in TimeManager::GetInstancePtr()->GetTimer(deadTimer)
	//and the deadTime
	mPosX = GraphicManager::GetInstancePtr()->GetWidth() / 2 
		+ sinf(TimeManager::GetInstancePtr()->GetTimer(deadTimer) * 2 * M_PI / deadTime) * GraphicManager::GetInstancePtr()->GetWidth() / 6;

	//Move up 
	mPosY -= 100 * TimeManager::GetInstancePtr()->GetDeltaTime();
	
}

void Player::Update()
{
	// Check if is below the screen
	if (mPosY > GraphicManager::GetInstancePtr()->GetHeight() && !isDead) {
		this->SetTexture("Body3");
		mVelY = 0;

		deadTimer = TimeManager::GetInstancePtr()->StartTimer(deadTime);
		head->setOutOfBounds();
		isDead = true;
	}
	
	if (!isDead)
		Move();
	else
	{
		if (!TimeManager::GetInstancePtr()->IsTimerActive(deadTimer))
		{
			//Reset the player
			isDead = false;
			SetTexture("Body1");
		}
		else
			DeadMove();
	}
}

