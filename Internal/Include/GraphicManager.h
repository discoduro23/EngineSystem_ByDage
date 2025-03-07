#pragma once

//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <SDL_ttf.h>
#include "Singleton.h"
#include "ObjectManager.h"
#include <iostream>
#include <vector>
#include <map>
#include "Text.h"


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
		int mWidth = 2080; //default 640
		int mHeight = 420; //default 480



	//array of TTF_Font
	std::map<std::string, TTF_Font*> mFonts;

	// Private constructor to avoid more than one instance
	GraphicManager() {};

	//BG image
	SDL_Texture* mBGTexture = nullptr;
	
	SDL_Texture* mTextureText = nullptr;

	std::vector<Text*> mTexts = std::vector<Text*>();

	//Data access semaphore
	SDL_sem* gDataLock = nullptr;

	//The "data buffer"
	int gData = -1;

	/*****************************************************************************/

public:
	// Initialize the graphic manager
	bool Init(int, int);

	//Set texture to the Background
	void SetBGTexture(SDL_Texture* texture) { mBGTexture = texture; }

	//Set height
	void SetHeight(int height) { mHeight = height; }
	
	//Set width
	void SetWidth(int width) { mWidth = width; }

	//Set height and width
	void SetSize(int width, int height) { mWidth = width; mHeight = height; }
		
	// Destroy the graphic manager
	void Destroy();

	// Clear the screen
	void Clear();

	// Update the screen
	void Update();

	// Load a texture
	SDL_Texture* LoadTexture(std::string);

	bool LoadTexturesFromPath(std::string relativePath, Object* obj);

	// Viewport
	void SetViewport(SDL_Rect* rect);
	void SetViewport(int x, int y, int w, int h);

	// Scale
	void SetScale(float scale);
	void SetScale(float scaleX, float scaleY);
	
	// Get the renderer
	SDL_Renderer* GetRenderer();

	//Get screen width
	int GetWidth() const { return mWidth; };
	
	//Get screen height
	int GetHeight() const { return mHeight; };

	//Get window
	SDL_Window* GetWindow() const { return mWindow; };
	
	// Render a texture

	void Render(SDL_Texture* texture, int x, int y, int w, int h, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip);

	// Render Text
	void RenderText(Text* text);

	void RenderAll();
	
	void UpdateScreen();

	bool loadFont(std::string path, std::string name, int size = 28);
	
	Text& CreateText(std::string const& textName, std::string const& text, std::string const& font, int x, int y, SDL_Color color = { 0,0,0,255 }) {
		Text* t = new Text(textName, text, color, x, y, font);
		mTexts.push_back(t);
		return *t;
	};

	void AddText(Text* text) { mTexts.push_back(text); };

	void ClearTexts() { mTexts.clear(); };
	
	void RemoveText(std::string textName);
	
	void ChangeWText(std::string textName, std::string text);

	/*****************************************************************************/

};