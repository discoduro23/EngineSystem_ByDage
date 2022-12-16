#include "Particle.h"

Particle::Particle(float x, float y, SDL_Texture* texture, SDL_Texture* brightTexture = nullptr) 
    : mTexture(texture), mBrightTexture(brightTexture)
{

    //Set offsets
    mPosX = x - 50 + (rand() % 25);
    mPosY = y - 50 + (rand() % 25);

    //Initialize animation
    mFrame = rand() % 5;
}

bool Particle::IsDead()
{
	return TIME_ALIVE > mFrame;
}

void Particle::Update()
{
	
	mFrame++;
}

SDL_Texture* Particle::getParticleTexture()
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
