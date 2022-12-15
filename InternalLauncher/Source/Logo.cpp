#include "Logo.h"

void Logo::Update()
{	
	if (isInit) {
		SetTexture("L(" + std::to_string(currentFrame) + ")");
		tM = TimeManager::GetInstancePtr();
		timerId = tM->StartTimer(frameTime);
	}

	//Easter Egg!
	if (InputManager::GetInstance().MouseLeftClick()) {

		int frameXSeparation = GraphicManager::GetInstance().GetWidth() / (23 - 9); //Frame selection is 9-23
		int frameSelection = (InputManager::GetInstance().GetMouseX() - frameXSeparation) / frameXSeparation;

		if (frameSelection > 0 && frameSelection < (23 - 9)) {
			//Invert the frame selection
			currentFrame = 23 - frameSelection;
			SetTexture("L(" + std::to_string(currentFrame) + ")");
		}

	}
	else if (!tM->IsTimerActive(timerId)) {
		
		SetTexture("L(" + std::to_string(currentFrame) + ")");

		currentFrame++;
		if (currentFrame > mTextureArray.size()) currentFrame = 1;
		
		timerId = tM->StartTimer(frameTime);
	}

	
}
