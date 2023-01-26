#include "Button.h"

void Button::handleevent()
{
	//Check if mouse is in button
	bool inside = coordIsInside(InputManager::GetInstance().GetMouseX(), InputManager::GetInstance().GetMouseY());
	//Mouse is outside button
	if (!inside)
	{
		SetTexture(deselected);
		isInZone = false;
	}
	//Mouse is inside button
	else
	{
		//Set mouse over sprite
		SetTexture(selected);
		isInZone = true;
	}

	if (InputManager::GetInstance().MouseLeftClick() && isInZone) {
		SoundManager::GetInstance().StopMusic("bgMusic");
		SDL_MinimizeWindow(GraphicManager::GetInstance().GetWindow());
#if (_DEBUG)
			std::string command = "..\\..\\RELEASEGames\\" + GetName() + '\\' + GetName() + ".exe -P";
			system((command).c_str());
#endif
#if (!_DEBUG)
			
			std::string command = ".\\" + GetName() + "\\" + GetName() + ".exe -P";
			
			//WinExec((command).c_str(), SW_SHOW);
			system((command).c_str());
#endif
			SDL_RestoreWindow(GraphicManager::GetInstance().GetWindow());
	}	
}
