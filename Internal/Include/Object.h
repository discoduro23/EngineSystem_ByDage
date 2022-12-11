#pragma once

//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <map>
#include <Windows.h>
#include <filesystem>
#include <vector>


class Object
{
protected:

	bool isInit = true;
	//name of the object
	std::string mName;
	
	//The X and Y offsets of the Object
	float mPosX, mPosY;

	//The dimensions of the Object
	int mWidth, mHeight;

	bool isCollisionable = false;
	
	//The texture of the Object that is going to be rendered
	SDL_Texture* mTexture;

	// array of textures
	std::map<std::string, SDL_Texture*> mTextureArray;


	
public:
	Object(std::string const& name, float x = 0, float y = 0, int w = 0, int h = 0, bool isCol = false, SDL_Texture* texture = nullptr) 
		: mName(name), mPosX(x), mPosY(y), mWidth(w), mHeight(h), isCollisionable(isCol), mTexture(texture) {};
	
	
	
	void AddTextureToArray(std::string const& name, SDL_Texture* texture) { mTextureArray[name] = texture; }
	SDL_Texture* GetTexture() { return mTexture; };
	void SetTexture(std::string const& name) { mTexture = mTextureArray[name]; }
	
	
	float GetX() const { return mPosX; };
	float GetY() const { return mPosY; };
	void SetX(float x) { mPosX = x; };
	void SetY(float y) { mPosY = y; };
	int GetWidth() const { return mWidth; };
	int GetHeight() const { return mHeight; };
	std::string GetName() const { return mName; };
	
	
	SDL_Rect GetRect() const { return { (int)mPosX, (int)mPosY, mWidth, mHeight }; };
	bool isCollision() const { return isCollisionable; };
	
	
	bool isInitialized() const { return isInit; };
	void setInit() { isInit = false; };

	virtual void Update();
	virtual ~Object() {
		for (std::map<std::string, SDL_Texture*>::iterator it = mTextureArray.begin(); it != mTextureArray.end(); ++it)
		{
			SDL_DestroyTexture(it->second);
		}
	};

};