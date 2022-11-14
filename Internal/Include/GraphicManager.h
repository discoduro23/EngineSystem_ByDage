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
	SDL_Window* mWindow;

	// Renderer
	SDL_Renderer* mRenderer;

	//Screen dimension constants
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;

	//array of LTexture
	LTexture* mTexture;

	// Private constructor to avoid more than one instance
	GraphicManager() {};

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
	SDL_Texture* LoadTexture(std::string path);
	
	// Render a texture
	void RenderTexture(LTexture* texture, int x, int y, int w, int h);
	

	// Get the renderer
	SDL_Renderer* GetRenderer();

	/*****************************************************************************/

};