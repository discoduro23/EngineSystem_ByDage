#include "Particle.h"

Particle::Particle(float x, float y, int width , int height,  SDL_Texture* texture, SDL_Texture* brightTexture = nullptr) 
    : mTexture(texture), mBrightTexture(brightTexture)
{
    //Set offsets randomly
	if (width == 0 || height == 0)
	{
		mPosX = x - 5 + (rand() % 25);
		mPosY = y - 5 + (rand() % 25);
	}
	else
	{
        mPosX = x + (rand() % width - width / 2);
        mPosY = y + (rand() % height - height / 2);
	}
    
    //Initialize animation
    mFrame = rand() % 5;
}

bool Particle::IsDead()
{
	return TIME_ALIVE < mFrame;
}

void Particle::Update()
{
    srand(time(nullptr));
	mFrame++;
}

void Particle::Respawn(float x, float y, int width, int height)
{
    if (width == 0 || height == 0)
    {
        mPosX = x - 5 + (rand() % 25);
        mPosY = y - 5 + (rand() % 25);
    }
    else
    {
        mPosX = x + (rand() % width - width / 2);
        mPosY = y + (rand() % height - height / 2);
    }

    //Initialize animation
    mFrame = rand() % 5;
}

SDL_Texture* Particle::GetTexture()
{

    if (mBrightTexture != nullptr)
    {
        if (mFrame % 2 == 0)
            return mBrightTexture;
        else
            return mTexture;

    }
	else
		return mTexture;
         
}
