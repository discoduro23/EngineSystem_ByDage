//GAME

#include <GameManager.h>


void GameManager::Update()
{
	GraphicManager* grM = GraphicManager::GetInstancePtr();
	
	//All inside isInit will be executed only once and at start
	if (isInit) {


		//Set the background
		grM->SetBGTexture(grM->LoadTexture("../../Media/images/background.png"));

		//Set fonts
		grM->GetInstance().loadFont("../../Media/fonts/PIXEL.TTF", "pixel_40", 40);
		grM->GetInstance().loadFont("../../Media/fonts/PIXEL.TTF", "pixel_60", 60);
		grM->GetInstance().loadFont("../../Media/fonts/PIXEL.TTF", "pixel_20", 20);


		//Make the knight
		knight = new Knight("knight", grM->GetWidth()/2 -130, grM->GetHeight() / 2, 20, 20, 0);
		grM->LoadTexturesFromPath("../../Media/images/Knight/", knight);
		knight->SetTexture("Paso1");

		//"Add object" section
		ObjectManager::GetInstance().AddObject(knight);
			
		//Make the goblin
		goblin = new Goblin("goblin", grM->GetWidth() / 2 + 100, grM->GetHeight() / 2, 20, 20, 1);
		
		grM->LoadTexturesFromPath("../../Media/images/Goblin/", goblin);
		goblin->SetTexture("Paso1");

		ObjectManager::GetInstance().AddObject(goblin);
		
		//Sounds
		SoundManager::GetInstance().LoadSound("../../Media/sounds/GoblinDrum.wav", "GoblinDrum");
		SoundManager::GetInstance().LoadSound("../../Media/sounds/KnightSlash.wav", "KnightSlash");
		
		//Music By Dream Protocol in pixabay
		SoundManager::GetInstance().LoadMusic("../../Media/sounds/feedthemachine.mp3", "bgMusic");
		SoundManager::GetInstance().PlayMusic("bgMusic", -1);
		SoundManager::GetInstance().SetMusicVolume("bgMusic", 50);
		
		//create text
		Text* BaseText =new Text("BaseTxt", "Score:", { 255,255,255 }, 170, 150, "pixel_40");
		grM->AddText(BaseText);
		
		Text* ScoreText = new Text("Score", "0", { 180,20,20 }, grM->GetWidth() / 2 - 30, grM->GetHeight() / 2, "pixel_60");
		grM->AddText(ScoreText);

		Text* loseText = new Text("lose", "Goblin Survive Time:", { 255,255,255 }, 40, 40, "pixel_20");
		grM->AddText(loseText);
		
		Text* timerText = new Text("timer", "15", { 255,255,255 }, 350, 40, "pixel_20");
		grM->AddText(timerText);

		timerId = TimeManager::GetInstance().StartTimer(15.0f);

	}
	
	if (!TimeManager::GetInstance().IsTimerActive(timerId)) {
		score--;
		SoundManager::GetInstance().PlayASound(-1, "GoblinDrum");
		timerId = TimeManager::GetInstance().StartTimer(15.0f);
		grM->ChangeWText("Score", std::to_string(score));
	}

	if (PhysicsManager::GetInstance().CheckCollision(knight->GetRect(), goblin->GetRect())) {
		score++;
		SoundManager::GetInstance().PlayASound(-1, "KnightSlash");
		goblin->SetX(0 + rand() / (RAND_MAX / ((grM->GetWidth()-goblin->GetWidth()) - 0 + 1 ) + 1));
		goblin->SetY(0 + rand() / (RAND_MAX / ((grM->GetHeight() - goblin->GetHeight()) - 0 + 1 ) + 1));
		timerId = TimeManager::GetInstance().StartTimer(10.0f);
		grM->ChangeWText("Score", std::to_string(score));
	}
	grM->ChangeWText("timer", std::to_string(1 + (int)TimeManager::GetInstance().GetTimer(timerId)));
}

void GameManager::Destroy()
{	
}


