#pragma once

//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

#include <iostream>

class Object
{
private:

	//name of the object
	std::string mName;
	
	//ID of the object
	int mID;
	
	//The X and Y offsets of the Object
	int mPosX, mPosY;

	//The velocity of the Object
	int mVelX, mVelY;

	//The dimensions of the Object
	int mWidth, mHeight;


	
public:
	Object(std::string name, int id, int x = 0, int y = 0, int w = 0, int h = 0) {
		{
			mName = name;
			mID = id;
			mPosX = x;
			mPosY = y;
			mWidth = w;
			mHeight = h;
		}
	};
	~Object();
	
	virtual void Update();
	
};