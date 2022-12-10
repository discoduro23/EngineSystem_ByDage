#pragma once

//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

#include "Singleton.h"
#include "ObjectManager.h"
#include "LTexture.h"
#include <iostream>
#include <vector>

/**
Input Manager class
*/
class GraphicManager :public Singleton<GraphicManager> {
	/*****************************************************************************/
	friend class Singleton<GraphicManager>;
	/*****************************************************************************/
private:
	// Window
	SDL_Window* mWindow = nullptr;

	// Renderer
	SDL_Renderer* mRenderer = nullptr;

	//Screen dimension constants
		int mWidth = 512; //default 640
		int mHeight = 480; //default 480

	//array of LTexture
	std::vector<LTexture*> mTextures;

	// Private constructor to avoid more than one instance
	GraphicManager() {};

	//BG image
	SDL_Texture* mBGTexture = nullptr;

	/*****************************************************************************/

public:
	// Initialize the graphic manager
	bool Init();

	//Set texture to the Background
	void SetBGTexture(SDL_Texture* texture) { mBGTexture = texture; }
	
	// Destroy the graphic manager
	void Destroy();

	// Clear the screen
	void Clear();

	// Update the screen
	void Update();

	// Load a texture
	SDL_Texture* LoadTexture(std::string);
	
	// Get the renderer
	SDL_Renderer* GetRenderer();

	//Get screen width
	int GetWidth() { return mWidth; };
	
	//Get screen height
	int GetHeight() { return mHeight; };
	
	// Render a texture

	void Render(SDL_Texture* texture, int x, int y, int w, int h, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip);

	void RenderAll();
	
	void UpdateScreen();

	

	/*****************************************************************************/

};