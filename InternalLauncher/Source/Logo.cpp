#include "Logo.h"

void Logo::Update()
{	
	if (isInit) {
		SetTexture("(" + std::to_string(currentFrame) + ")");
		tM = TimeManager::GetInstancePtr();
		timerId = tM->StartTimer(frameTime);
	}
	
	std::cout << "Logo Update" << timerId << mTextureArray.size() << std::endl;

	if (tM->IsTimerActive(timerId)) {
		
		SetTexture("(" + std::to_string(currentFrame) + ")");

		currentFrame++;
		if (currentFrame > mTextureArray.size()) currentFrame = 0;

		timerId = tM->StartTimer(frameTime);
	}
}
