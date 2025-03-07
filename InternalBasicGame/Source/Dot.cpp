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
		

	default:
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
		mPosX += mVelX * TimeManager::GetInstance().GetDeltaTime();
		//Move the dot up or down
		mPosY += mVelY * TimeManager::GetInstance().GetDeltaTime();
		
			//If the dot went too far to the left or right
		if (((mPosX < 0) || (mPosX + mWidth >= GraphicManager::GetInstance().GetWidth()) ))
		{
			//Move back
			mPosX -= mVelX * TimeManager::GetInstance().GetDeltaTime();
		}

		//If the dot went too far up or down
		if (((mPosY < 0) || (mPosY + mHeight >= GraphicManager::GetInstance().GetHeight()) ))
		{
			//Move back
			mPosY -= mVelY * TimeManager::GetInstance().GetDeltaTime();
		}
		
}

void Dot::Update()
{
	move(moveMode);
	std::cout << "  " << GetName() + " Colliding: " << (int)(PhysicsManager::GetInstance().CheckCollisionAll(this->GetRect(), this->GetName()))<<std::endl;
}
