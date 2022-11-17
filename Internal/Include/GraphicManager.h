#pragma once

//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

#include "Singleton.h"
#include "LTexture.h"
#include <iostream>

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
	int mWidth = 640;
	int mHeight = 480;

	//array of LTexture
	LTexture* mTexture;

	// Private constructor to avoid more than one instance
	GraphicManager();

	/*****************************************************************************/

public:
	// Initialize the graphic manager
	bool Init();

	// Destroy the graphic manager
	void Destroy();

	// Clear the screen
	void Clear();

	// Update the screen
	void Update();

	// Load a texture
	SDL_Texture* LoadTexture(std::string, LTexture*);
	
	// Render a texture

	void Render(SDL_Texture* texture, int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip);
	

	// Get the renderer
	SDL_Renderer* GetRenderer();

	/*****************************************************************************/

};