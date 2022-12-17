#include "Particle.h"

Particle::Particle(float x, float y, int width , int height,  SDL_Texture* texture, SDL_Texture* brightTexture = nullptr) 
    : mTexture(texture), mBrightTexture(brightTexture)
{
    std::random_device rd;  // Random device used to seed the generator
    std::mt19937 rng(rd());  // Mersenne Twister generator with a randomly-seeded seed
    std::uniform_int_distribution<int> frameDist(0, TIME_ALIVE - 1);  // Distribution for the frame number (0-4)
    std::uniform_int_distribution<int> offsetDistX(0, width); // Distribution for the x offset (-width/2 to width/2)
    std::uniform_int_distribution<int> offsetDistY(0, height); // Distribution for the y offset (-height/2 to height/2)

    //Initialize animation
    mFrame = frameDist(rng);

    //Set offsets randomly
    if (width == 0 || height == 0)
    {
        mPosX = x;
        mPosY = y;
    }
    else
    {
        mPosX = x  + offsetDistX(rng) / 2;
        mPosY = y  + offsetDistY(rng) / 2;
    }
}

bool Particle::IsDead()
{
	return TIME_ALIVE < mFrame;
}

void Particle::Update()
{
	mFrame++;
}

void Particle::Respawn(float x, float y, int width, int height)
{
    std::random_device rd;  // Random device used to seed the generator
    std::mt19937 rng(rd());  // Mersenne Twister generator with a randomly-seeded seed
    std::uniform_int_distribution<int> frameDist(0, TIME_ALIVE - 1);  // Distribution for the frame number (0-4)
    std::uniform_int_distribution<int> offsetDistX(0, width); // Distribution for the x offset (-width/2 to width/2)
    std::uniform_int_distribution<int> offsetDistY(0, height); // Distribution for the y offset (-height/2 to height/2)
    
    //Initialize animation
    mFrame = frameDist(rng);

    //Set offsets randomly
    if (width == 0 || height == 0)
    {
        mPosX = x;
        mPosY = y;
    }
    else
    {
        mPosX = x + offsetDistX(rng)/2;
        mPosY = y + offsetDistY(rng)/2;
    }
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
