#include "Logo.h"

void Logo::Update()
{	
	if (isInit) {
		SetTexture("L(" + std::to_string(currentFrame) + ")");
		tM = TimeManager::GetInstancePtr();
		timerId = tM->StartTimer(frameTime);
	}
	

	if (!tM->IsTimerActive(timerId)) {
		
		SetTexture("L(" + std::to_string(currentFrame) + ")");

		currentFrame++;
		if (currentFrame > mTextureArray.size()) currentFrame = 1;
		
		timerId = tM->StartTimer(frameTime);
	}
}
