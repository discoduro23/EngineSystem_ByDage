//BASIC GAME

#include <GameManager.h>
void GameManager::Update()
{
	GraphicManager* grM = GraphicManager::GetInstancePtr();
	
	//All inside isInit will be executed only once and at start
	if (isInit) {
		

		//Set the background
		grM->SetBGTexture(grM->LoadTexture("../../Media/images/background.png"));

		
		Dot* dot1("dot1", 20, 20, 20, 20,
			grM->LoadTexture("../../Media/images/dotARROW.bmp"), 0);
		Dot dot2("dot2", 40, 40, 20, 20,
			grM->LoadTexture("../../Media/images/dotWASD.bmp"), 1);
		Dot dot3("dot3", 60, 60, 20, 20,
			grM->LoadTexture("../../Media/images/dot.bmp"), 2);

		ObjectManager::GetInstance().AddObject(&dot1);
		ObjectManager::GetInstance().AddObject(&dot2);
		ObjectManager::GetInstance().AddObject(&dot3);
		
		
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


