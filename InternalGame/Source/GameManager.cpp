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
		
		//Make the knight
		knight = new Knight("knight", 20, 20, 20, 20,
			grM->LoadTexture("../../Media/images/Knight.png"), 0);

		//"Add object" section
		ObjectManager::GetInstance().AddObject(knight);

		goblin = new Goblin("goblin", 40, 40, 20, 20,
			grM->LoadTexture("../../Media/images/Goblin.png"), 1);

		ObjectManager::GetInstance().AddObject(goblin);

		//Sounds
		SoundManager::GetInstance().LoadSound("../../Media/sounds/beat.wav", "beat");
		timerId = TimeManager::GetInstance().StartTimer(5.0f);
		
		//create a text
		Text* text =new Text("BaseTxt", "Puntuacion:", { 255,255,255 }, 100, 100, "pixel_40");
		grM->AddText(text);
	}
	
	if (!TimeManager::GetInstance().IsTimerActive(timerId)) {
		SoundManager::GetInstance().PlaySound(-1, "beat");
		timerId = TimeManager::GetInstance().StartTimer(60.0f);
	}

	if (PhysicsManager::GetInstance().CheckCollision(knight->GetRect(), goblin->GetRect())) {
		std::cout << "Collision" << std::endl;
	}
}

void GameManager::Destroy()
{	
}


