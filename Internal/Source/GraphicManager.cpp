
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
		mWindow = SDL_CreateWindow("DefaultName", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, mWidth, mHeight, SDL_WINDOW_SHOWN);
		if (mWindow == nullptr)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create vsynced renderer for window
			mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (mRenderer == nullptr)
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
	mWindow = nullptr;
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
	if(mBGTexture!=nullptr) Render(mBGTexture, 0, 0, mWidth, mHeight, nullptr, 0.0, nullptr, SDL_FLIP_NONE);
	RenderAll();
	if (gDataLock == nullptr)
	{
		printf("SDL_CreateSemaphore Error: %s\n", SDL_GetError());
	}
	else SDL_SemPost(gDataLock);
	UpdateScreen();
}

SDL_Texture* GraphicManager::LoadTexture(std::string path)
{

	//The final texture
	SDL_Texture* newTexture = nullptr;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == nullptr)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Color key image
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(mRenderer, loadedSurface);
		if (newTexture == nullptr)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}
	
	return newTexture;
}

bool GraphicManager::LoadTexturesFromPath(std::string relativePath, Object* obj)
{

	// The relative path to the directory containing the files
	std::string path = relativePath;

	std::vector<std::string> file_paths;

	//Read all the entries
	for (const auto& entry : std::filesystem::directory_iterator(path))
	{
		//Get the path to the file
		std::string file_path = entry.path().string();

		//Get the file name and erase the extension of the file after the last dot
		std::string file_name = entry.path().filename().string();
		file_name.erase(file_name.find_last_of("."), std::string::npos);

		obj->AddTextureToArray(file_name, GraphicManager::GetInstance().LoadTexture(file_path));
	}
	return false;
}

void GraphicManager::SetViewport(SDL_Rect* rect)
{
	SDL_RenderSetViewport(mRenderer, rect);
}

void GraphicManager::SetViewport(int x, int y, int w, int h)
{
	SDL_Rect rect = { x, y, w, h };
	SDL_RenderSetViewport(mRenderer, &rect);
}

void GraphicManager::SetScale(float scale)
{
	SDL_RenderSetScale(mRenderer, scale, scale);
}

void GraphicManager::SetScale(float scaleX, float scaleY)
{
	SDL_RenderSetScale(mRenderer, scaleX, scaleY);
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
	if (clip != nullptr)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopyEx(mRenderer, texture, clip, &renderQuad, angle, center, flip);
}

void GraphicManager::RenderAll()
{
	size_t Textsize = mTexts.size();
	for (int i = 0; i < Textsize; i++) {
		RenderText(mTexts[i]);
	}

	size_t size = ObjectManager::GetInstance().GetObjectCount();
	Object* ob = nullptr;
	for (int i = 0; i < size;i++) {
		ob = ObjectManager::GetInstance().GetAObject(i);
		if (ob->GetTexture() != nullptr) {
			//There are particles?
			if (ob->GetParticleCount() > 0)
			{
				ob->UpdateParticles();
				for (int j = 0; j < ob->GetParticleCount(); j++)
				{
					Render(
						ob->GetParticle(j)->GetTexture(),
						ob->GetParticle(j)->GetX(),
						ob->GetParticle(j)->GetY(),
						5,
						5,
						nullptr,
						0.0,
						nullptr,
						SDL_FLIP_NONE);
				}
			}
			Render(
				ob->GetTexture(),
				ob->GetX(),
				ob->GetY(),
				ob->GetWidth(),
				ob->GetHeight(),
				nullptr,
				0.0,
				nullptr,
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
	if (Font == nullptr)
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
	if (textSurface == nullptr)
	{
		printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
	}
	else
	{
		//Create texture from surface pixels
		mTextureText = SDL_CreateTextureFromSurface(mRenderer, textSurface);
		if (mTextureText == nullptr)
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
	Render(mTextureText, textC->GetX(), textC->GetY(), w, h, nullptr, 0.0, nullptr, SDL_FLIP_NONE);

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