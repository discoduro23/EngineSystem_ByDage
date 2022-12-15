#include "Particle.h"

Particle::Particle(int x, int y, SDL_Texture* texture, SDL_Texture* brightTexture = nullptr) 
    : mTexture(texture), mBrightTexture(brightTexture)
{

    //Set offsets
    mPosX = x - 5 + (rand() % 25);
    mPosY = y - 5 + (rand() % 25);

    //Initialize animation
    mFrame = rand() % 5;
}

bool Particle::IsDead()
{
	return TIME_ALIVE > mFrame;
}
