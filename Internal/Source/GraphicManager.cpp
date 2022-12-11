
#include "GraphicManager.h"


bool GraphicManager::Init(int w, int h)
{
	//Set size
	mWidth = w;
	mHeight = h;

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

		//Initialize PNG loading
		int imgFlags = IMG_INIT_PNG;
		if (!(IMG_Init(imgFlags) & imgFlags))
		{
			printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
			success = false;
		}

		//Initialize SDL_ttf
		if (TTF_Init() == -1)
		{
			printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
			success = false;
		}
	}
	return success;
}

void GraphicManager::Destroy()
{
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
	gDataLock = SDL_CreateSemaphore(1);
	SDL_SemWait(gDataLock);
	
	Clear();
	if(mBGTexture!=NULL) Render(mBGTexture, 0, 0, mWidth, mHeight, NULL, 0.0, NULL, SDL_FLIP_NONE);
	RenderAll();
	UpdateScreen();
	SDL_SemPost(gDataLock);
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
	int Textsize = mTexts.size();
	for (int i = 0; i < Textsize; i++) {
		RenderText(mTexts[i]);
	}

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

bool GraphicManager::loadFont(std::string path, std::string name, int size)
{
	//Loading success flag
	bool success = true;
	TTF_Font* Font;

	//Open the font
	Font = TTF_OpenFont(path.c_str(), size);
	if (Font == NULL)
	{
		printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
		success = false;
	}
	mFonts[name] = Font;

	return success;
}

void GraphicManager::RenderText(Text* textC)
{
	gDataLock = SDL_CreateSemaphore(1);
	SDL_SemWait(gDataLock);
	
	int w=0, h=0;
	//Render text surface
	SDL_Surface* textSurface = TTF_RenderText_Solid(mFonts[textC->GetFont()], textC->GetText().c_str(), textC->GetColor());
	if (textSurface == NULL)
	{
		printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
	}
	else
	{
		//Create texture from surface pixels
		mTextureText = SDL_CreateTextureFromSurface(mRenderer, textSurface);
		if (mTextureText == NULL)
		{
			printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
		}
		else
		{
			//Get image dimensions
			w = textSurface->w;
			h = textSurface->h;
		}

		//Get rid of old surface
		SDL_FreeSurface(textSurface);
	}
	Render(mTextureText, textC->GetX(), textC->GetY(), w, h, NULL, 0.0, NULL, SDL_FLIP_NONE);

	SDL_SemPost(gDataLock);
}

void GraphicManager::RemoveText(std::string textName) {
	for (int i = 0; i < mTexts.size(); i++) {
		if (mTexts[i]->GetName() == textName) {
			mTexts.erase(mTexts.begin() + i);
			return;
		}
	}
}

void GraphicManager::ChangeWText(std::string textName, std::string text) {
	for (int i = 0; i < mTexts.size(); i++) {
		if (mTexts[i]->GetName() == textName) {
			mTexts[i]->SetText(text);
			return;
		}
	}
}