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
		std::string backgroundPath = "../../Media/images/background.png";
		std::string pixelFontPath = "../../Media/fonts/PIXEL.TTF";
		std::string knightFolderPath = "../../Media/images/Knight/";
		std::string goblinFolderPath = "../../Media/images/Goblin/";
		std::string goblinDrumPath = "../../Media/sounds/GoblinDrum.wav";
		std::string knightSlashPath = "../../Media/sounds/KnightSlash.wav";
		std::string bgMusicPath = "../../Media/sounds/feedthemachine.mp3";
		
#endif
#if (!_DEBUG)
		std::string backgroundPath = "./Media/images/background.png";
		std::string pixelFontPath = "./Media/fonts/PIXEL.TTF";
		std::string knightFolderPath = "./Media/images/Knight/";
		std::string goblinFolderPath = "./Media/images/Goblin/";
		std::string goblinDrumPath = "./Media/sounds/GoblinDrum.wav";
		std::string knightSlashPath = "./Media/sounds/KnightSlash.wav";
		std::string bgMusicPath = "./Media/sounds/feedthemachine.mp3";
#endif


		//Set the background
		grM->SetBGTexture(grM->LoadTexture(backgroundPath));

		//Set fonts
		grM->loadFont(pixelFontPath, "pixel_40", 40);
		grM->loadFont(pixelFontPath, "pixel_60", 60);
		grM->loadFont(pixelFontPath, "pixel_20", 20);
		grM->loadFont(pixelFontPath, "pixel_15", 15);


		//Make the knight
		knight = new Knight("knight", grM->GetWidth() / 2 - 130, grM->GetHeight() / 2, 20, 20, 0);
		grM->LoadTexturesFromPath(knightFolderPath, knight);
		knight->SetTexture("Paso1");

		//"Add object" section
		oM->AddObject(knight);

		//Make the goblin
		goblin = new Goblin("goblin", grM->GetWidth() / 2 + 100, grM->GetHeight() / 2, 20, 20, 1);

		grM->LoadTexturesFromPath(goblinFolderPath, goblin);
		goblin->SetTexture("Paso1");

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

		timerId = tM->StartTimer(15.0f);

	}

	grM->ChangeWText("timer", std::to_string(1 + (int)tM->GetTimer(timerId)));
	grM->ChangeWText("FPSValue", std::to_string((int)tM->GetFPS()));

	if (!tM->IsTimerActive(timerId)) {
		score--;
		sM->PlayASound(-1, "GoblinDrum");
		timerId = tM->StartTimer(15.0f);
		grM->ChangeWText("Score", std::to_string(score));
	}

	if (PhysicsManager::GetInstance().CheckCollision(knight->GetRect(), goblin->GetRect())) {
		score++;
		sM->PlayASound(-1, "KnightSlash");
		goblin->SetX(0 + rand() / (RAND_MAX / ((grM->GetWidth() - goblin->GetWidth()) - 0 + 1) + 1));
		goblin->SetY(0 + rand() / (RAND_MAX / ((grM->GetHeight() - goblin->GetHeight()) - 0 + 1) + 1));
		timerId = tM->StartTimer(10.0f);
		grM->ChangeWText("Score", std::to_string(score));
	}

}

void GameManager::Destroy()
{
}

void GameManager::SaveGameState()
{
	
}
