#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <cstdlib>

#define TIME_ALIVE 10

class Particle
{
public:
    //Initialize position and animation
    Particle(int x, int y, SDL_Texture* texture, SDL_Texture* brightTexture = nullptr);

    //Shows the particle
    void render();

    //Checks if particle is dead
    bool IsDead();

    //Update
	void Update();

private:
    //Offsets
    int mPosX, mPosY;

    //Current frame of animation
    int mFrame;

    //Type of particle
    SDL_Texture* mTexture;

    //Type of particle
    SDL_Texture* mBrightTexture;
};