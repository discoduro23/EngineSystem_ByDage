#pragma once

//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

#include <iostream>

class Object
{
protected:

	bool isInit = true;

	//name of the object
	std::string mName;
	
	//The X and Y offsets of the Object
	int mPosX, mPosY;

	//The dimensions of the Object
	int mWidth, mHeight;
	
	//The texture of the Object
	SDL_Texture* mTexture;


	
public:
	Object(std::string name, int x = 0, int y = 0, int w = 0, int h = 0, SDL_Texture* texture = NULL)
	{
		mName = name;
		mPosX = x;
		mPosY = y;
		mWidth = w;
		mHeight = h;
		mTexture = texture;
	};
	SDL_Texture* GetTexture() { return mTexture; };
	int GetX() { return mPosX; };
	int GetY() { return mPosY; };
	std::string GetName() { return mName; };
	~Object();
	
	bool isInitialized() { return isInit; };
	void setInit() { isInit = true; };

	virtual void Update();
	
};