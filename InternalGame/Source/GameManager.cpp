//GAME

#include <GameManager.h>


void GameManager::Update()
{
	GraphicManager* grM = GraphicManager::GetInstancePtr();
	
	//All inside isInit will be executed only once and at start
	if (isInit) {

		//Set the background
		grM->SetBGTexture(grM->LoadTexture("../../Media/images/background.png"));

		//Make the knight
		Knight* knight = new Knight("knight", 20, 20, 20, 20,
			grM->LoadTexture("../../Media/images/Knight.png"), 0);

		//"Add object" section
		ObjectManager::GetInstance().AddObject(knight);

		Goblin* goblin = new Goblin("goblin", 40, 40, 20, 20,
			grM->LoadTexture("../../Media/images/Goblin.png"), 1);

		ObjectManager::GetInstance().AddObject(goblin);

		//Sounds
		SoundManager::GetInstance().LoadSound("../../Media/sounds/beat.wav", "beat");
		timerId = TimeManager::GetInstance().StartTimer(5.0f);
	}
	
	if (!TimeManager::GetInstance().IsTimerActive(timerId)) {
		SoundManager::GetInstance().PlaySound(-1, "beat");
		timerId = TimeManager::GetInstance().StartTimer(60.0f);
	}
}

void GameManager::Destroy()
{	
}


