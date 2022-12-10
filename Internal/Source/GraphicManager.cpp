
#include "GraphicManager.h"


bool GraphicManager::Init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create window
		mWindow = SDL_CreateWindow("Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, mWidth, mHeight, SDL_WINDOW_SHOWN);
		if (mWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create vsynced renderer for window
			mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (mRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(mRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
			}
		}
	}
	return success;
}

void GraphicManager::Destroy()
{
	//Free loaded images
	for (int i = 0; i < mTextures.size(); i++)
	{
		mTextures[i]->free();
	}

	// Destroy the window
	SDL_DestroyWindow(mWindow);
	mWindow = NULL;
}

void GraphicManager::Clear()
{
	// Clear the screen
	SDL_RenderClear(mRenderer);
}

void GraphicManager::Update()
{
	Clear();
	if(mBGTexture!=NULL) Render(mBGTexture, 0, 0, mWidth, mHeight, NULL, 0.0, NULL, SDL_FLIP_NONE);
	RenderAll();
	UpdateScreen();
}

SDL_Texture* GraphicManager::LoadTexture(std::string path)
{

	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Color key image
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(mRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}
	
	return newTexture;
}

void  GraphicManager::Render(SDL_Texture* texture, int x, int y, int w, int h, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
	if (texture == NULL)
	{
		printf("Texture is NULL");
		return;
	}
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, w, h };

	//Set clip rendering dimensions
	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopyEx(mRenderer, texture, clip, &renderQuad, angle, center, flip);
}

void GraphicManager::RenderAll()
{
	size_t size = ObjectManager::GetInstance().GetObjectCount();
	Object* ob = nullptr;
	for (int i = 0; i < size;i++) {
		ob = ObjectManager::GetInstance().GetObject(i);
		if (ob->GetTexture() != NULL) {
			Render(
				ob->GetTexture(), 
				ob->GetX(), 
				ob->GetY(),
				ob->GetWidth(),
				ob->GetHeight(),
				NULL,
				0.0,
				NULL,
				SDL_FLIP_NONE);
		}
	}
}

SDL_Renderer* GraphicManager::GetRenderer()
{
	return mRenderer;
}

void GraphicManager::UpdateScreen()
{
	SDL_RenderPresent(mRenderer);
}

