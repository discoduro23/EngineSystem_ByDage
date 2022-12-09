#include <GameManager.h>


void GameManager::Update()
{
	if (isInit) {
		SoundManager::GetInstance().LoadSound("../../Media/sounds/beat.wav", "beat");
		id = TimeManager::GetInstance().StartTimer(5.0f);
	}
	
	if (!TimeManager::GetInstance().IsTimerActive(id)) {
		SoundManager::GetInstance().PlaySound(-1, "beat");
		id = TimeManager::GetInstance().StartTimer(5.0f);
	}
}

void GameManager::Destroy()
{
	
}


