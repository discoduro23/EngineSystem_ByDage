#include <GameManager.h>


void GameManager::Update()
{
	GraphicManager* grM = GraphicManager::GetInstancePtr();
	
	//All inside isInit will be executed only once and at start
	if (isInit) {
		
		/*
		Dot dot1("dot1", 20, 20, 20, 20,
			grM->LoadTexture("../../Media/images/dotARROW.bmp"), 0);
		Dot dot2("dot2", 40, 40, 20, 20,
			grM->LoadTexture("../../Media/images/dotWASD.bmp"), 1);
		Dot dot3("dot3", 60, 60, 20, 20,
			grM->LoadTexture("../../Media/images/dot.bmp"), 2);

		ObjectManager::GetInstance().AddObject(&dot1);
		ObjectManager::GetInstance().AddObject(&dot2);
		ObjectManager::GetInstance().AddObject(&dot3);*/

		//Set the background
		grM->SetBGTexture(grM->LoadTexture("../../Media/images/background.png"));

		//Make the knight
		Knight* knight = new Knight("knight", 20, 20, 20, 20,
			grM->LoadTexture("../../Media/images/Knight.png"), 0);

		//"Add object" section
		ObjectManager::GetInstance().AddObject(knight);

		//Sounds
		SoundManager::GetInstance().LoadSound("../../Media/sounds/beat.wav", "beat");
		timerId = TimeManager::GetInstance().StartTimer(5.0f);
	}
	
	if (!TimeManager::GetInstance().IsTimerActive(timerId)) {
		SoundManager::GetInstance().PlaySound(-1, "beat");
		timerId = TimeManager::GetInstance().StartTimer(5.0f);
	}
}

void GameManager::Destroy()
{	
}


