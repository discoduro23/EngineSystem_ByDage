#pragma once

//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <map>

class Object
{
protected:

	bool isInit = true;
	bool isCollisionable = false;
	//name of the object
	std::string mName;
	
	//The X and Y offsets of the Object
	float mPosX, mPosY;

	//The dimensions of the Object
	int mWidth, mHeight;
	
	//The texture of the Object
	SDL_Texture* mTexture;

	// array of music
	std::map<std::string, SDL_Texture*> mTextureArray;


	
public:
	Object(std::string name, float x = 0, float y = 0, int w = 0, int h = 0, bool isCol = false)
	{
		mName = name;
		mPosX = x;
		mPosY = y;
		mWidth = w;
		mHeight = h;
		isCollisionable = isCol;
	};
	void AddTextureToArray(std::string name, SDL_Texture* texture) { mTextureArray[name] = texture; }
	SDL_Texture* GetTexture() { return mTexture; };
	void SetTexture(std::string name) { mTexture = mTextureArray[name]; }
	float GetX() { return mPosX; };
	float GetY() { return mPosY; };
	void SetX(float x) { mPosX = x; };
	void SetY(float y) { mPosY = y; };
	int GetWidth() { return mWidth; };
	int GetHeight() { return mHeight; };
	std::string GetName() { return mName; };
	SDL_Rect GetRect() { return { (int)mPosX, (int)mPosY, mWidth, mHeight }; };
	bool isCollision() { return isCollisionable; };
	
	bool isInitialized() { return isInit; };
	void setInit() { isInit = false; };

	virtual void Update();
		~Object();

};