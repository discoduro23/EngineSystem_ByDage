#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <random>

#define TIME_ALIVE 20

class Particle
{

private:
    //Offsets
    float mPosX, mPosY;


    //Type of particle
    SDL_Texture* mTexture;

    //Type of particle
    SDL_Texture* mBrightTexture;
    
public:

    //Current frame of animation
    int mFrame;
    //Initialize position and animation
    Particle(float x, float y, int width, int height, SDL_Texture* texture, SDL_Texture* brightTexture);
    
    //Checks if particle is dead
    bool IsDead();
    void Respawn(float x, float y, int width , int height);

    //Update
	virtual void Update();

    SDL_Texture* GetTexture();
    float GetX() const { return mPosX; };
    float GetY() const { return mPosY; };
	void SetX(float x) { mPosX = x; };
	void SetY(float y) { mPosY = y; };
};