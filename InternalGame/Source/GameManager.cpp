//GAME

#include <GameManager.h>


void GameManager::Update()
{

	//All inside isInit will be executed only once and at start
	if (isInit) {
		grM = GraphicManager::GetInstancePtr();
		tM = TimeManager::GetInstancePtr();
		oM = ObjectManager::GetInstancePtr();
		sM = SoundManager::GetInstancePtr();
		
#if (_DEBUG)
		std::string backgroundPath = "../../Media/HideAndWhere/images/background.png";
		std::string pixelFontPath = "../../Media/HideAndWhere/fonts/PIXEL.TTF";
		std::string knightFolderPath = "../../Media/HideAndWhere/images/Knight/";
		std::string goblinFolderPath = "../../Media/HideAndWhere/images/Goblin/";
		std::string goblinDrumPath = "../../Media/HideAndWhere/sounds/GoblinDrum.wav";
		std::string knightSlashPath = "../../Media/HideAndWhere/sounds/KnightSlash.wav";
		std::string bgMusicPath = "../../Media/HideAndWhere/sounds/feedthemachine.mp3";
		std::string particleBluePath = "../../Media/HideAndWhere/images/Particle/blue.bmp";
		std::string particleRedPath = "../../Media/HideAndWhere/images/Particle/red.bmp";
		std::string particleShimmerPath = "../../Media/HideAndWhere/images/Particle/shimmer.bmp";
		
#endif
#if (!_DEBUG)
		std::string backgroundPath = "./Media/images/background.png";
		std::string pixelFontPath = "./Media/fonts/PIXEL.TTF";
		std::string knightFolderPath = "./Media/images/Knight/";
		std::string goblinFolderPath = "./Media/images/Goblin/";
		std::string goblinDrumPath = "./Media/sounds/GoblinDrum.wav";
		std::string knightSlashPath = "./Media/sounds/KnightSlash.wav";
		std::string bgMusicPath = "./Media/sounds/feedthemachine.mp3";
		std::string particleBluePath = "./Media/images/Particle/blue.bmp";
		std::string particleRedPath = "../../Media/images/Particle/red.bmp";
		std::string particleShimmerPath = "./Media/images/Particle/shimmer.bmp";
#endif


		//Set the background
		grM->SetBGTexture(grM->LoadTexture(backgroundPath));

		//Set fonts
		grM->loadFont(pixelFontPath, "pixel_40", 40);
		grM->loadFont(pixelFontPath, "pixel_60", 60);
		grM->loadFont(pixelFontPath, "pixel_20", 20);
		grM->loadFont(pixelFontPath, "pixel_15", 15);


		//Make the knight
		knight = new Knight("knight", nullptr, grM->LoadTexture(particleBluePath), grM->LoadTexture(particleShimmerPath),
			grM->GetWidth() / 2 - 130, grM->GetHeight() / 2, 20, 20, 0, true);
		grM->LoadTexturesFromPath(knightFolderPath, knight);
		knight->SetTexture("Step1");
		oM->AddObject(knight);

		//Make the goblin
		goblin = new Goblin("goblin", nullptr, grM->LoadTexture(particleRedPath), grM->LoadTexture(particleShimmerPath),
			grM->GetWidth() / 2 + 100, grM->GetHeight() / 2, 20, 20, 1, true);
		grM->LoadTexturesFromPath(goblinFolderPath, goblin);
		goblin->SetTexture("Step1");
		oM->AddObject(goblin);

		//Sounds
		sM->LoadSound(goblinDrumPath, "GoblinDrum");
		sM->LoadSound(knightSlashPath, "KnightSlash");

		//Music By Dream Protocol in pixabay
		sM->LoadMusic(bgMusicPath, "bgMusic");
		sM->PlayMusic("bgMusic", -1);
		sM->SetMusicVolume("bgMusic", 50);

		//create text
		Text* BaseText = new Text("BaseTxt", "Score:", { 255,255,255 }, 170, 150, "pixel_40");
		grM->AddText(BaseText);

		Text* ScoreText = new Text("Score", "0", { 180,20,20 }, grM->GetWidth() / 2 - 30, grM->GetHeight() / 2, "pixel_60");
		grM->AddText(ScoreText);

		Text* loseText = new Text("lose", "Goblin Survive Time:", { 255,255,255 }, 40, 40, "pixel_20");
		grM->AddText(loseText);

		Text* timerText = new Text("timer", "15", { 255,255,255 }, 350, 40, "pixel_20");
		grM->AddText(timerText);

		Text* Fps = new Text("FPS", "FPS:", { 255,255,255 }, 30, grM->GetHeight() - 50, "pixel_15");
		grM->AddText(Fps);

		Text* FpsValue = new Text("FPSValue", "0", { 255,255,255 }, 75, grM->GetHeight() - 50, "pixel_15");
		grM->AddText(FpsValue);

		//Set the timer
		timerId = tM->StartTimer(15.0f);

	}


	
	//Update texts
	grM->ChangeWText("timer", std::to_string(1 + (int)tM->GetTimer(timerId)));
	grM->ChangeWText("FPSValue", std::to_string(tM->GetFPS()));

	//Check if the timer is over
	if (!tM->IsTimerActive(timerId)) {
		score--;
		sM->PlayASound(-1, "GoblinDrum");
		timerId = tM->StartTimer(15.0f);
		grM->ChangeWText("Score", std::to_string(score));
	}

	//Check collisions between 
	if (PhysicsManager::GetInstance().CheckCollision(knight->GetRect(), goblin->GetRect())) {
		score++;
		sM->PlayASound(-1, "KnightSlash");
		goblin->SetX(0 + rand() / (RAND_MAX / ((grM->GetWidth() - goblin->GetWidth()) - 0 + 1) + 1));
		goblin->SetY(0 + rand() / (RAND_MAX / ((grM->GetHeight() - goblin->GetHeight()) - 0 + 1) + 1));
		tM->StopTimer(timerId);
		timerId = tM->StartTimer(10.0f);
		grM->ChangeWText("Score", std::to_string(score));
	}

	//Save and load (K to Save, L to load)
	if (InputManager::GetInstance().GetKey(SDL_SCANCODE_K))
		SaveGameState();
	
	if (InputManager::GetInstance().GetKey(SDL_SCANCODE_L))
		LoadGameState();
}

void GameManager::Destroy()
{
}

void GameManager::SaveGameState()
{
	std::vector<std::string> saveData;
	saveData.push_back(std::to_string(score));
	saveData.push_back(std::to_string(knight->GetX()));
	saveData.push_back(std::to_string(knight->GetY()));
	saveData.push_back(std::to_string(goblin->GetX()));
	saveData.push_back(std::to_string(goblin->GetY()));
	
	SaveManager::GetInstance().storeFile(saveData, "Game");
}

void GameManager::LoadGameState()
{
	tM->StopTimer(timerId);
	timerId = tM->StartTimer(15.0f);
	
	std::vector<std::string> saveData = SaveManager::GetInstance().readFile("Game");
	score = std::stoi(saveData[0]);
	knight->SetX(std::stof(saveData[1]));
	knight->SetY(std::stof(saveData[2]));
	goblin->SetX(std::stof(saveData[3]));
	goblin->SetY(std::stof(saveData[4]));
	
	grM->ChangeWText("Score", std::to_string(score));

}
