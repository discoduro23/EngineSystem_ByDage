#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <cstdlib>

#define TIME_ALIVE 10

class Particle
{

private:
    //Offsets
    float mPosX, mPosY;

    //Current frame of animation
    int mFrame;

    //Type of particle
    SDL_Texture* mTexture;

    //Type of particle
    SDL_Texture* mBrightTexture;
    
public:
    //Initialize position and animation
    Particle(float x, float y, SDL_Texture* texture, SDL_Texture* brightTexture = nullptr);
    
    //Checks if particle is dead
    bool IsDead();

    //Update
	void Update();

    SDL_Texture* getParticleTexture();
    float getPosX() { return mPosX; };
    float getPosY() { return mPosY; };


};