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
		std::cout << "Game Hide and Where loaded" << std::endl;
#if (_DEBUG)
			std::string command = "..\\..\\RELEASEGames\\" + GetName() + '\\' + GetName() + ".exe -P";
			system((command).c_str());
#endif
#if (!_DEBUG)
			system((".\\" + GetName() + '\\' + GetName() + ".exe -P").c_str()); //no funciona, no se porque
#endif
			SDL_RestoreWindow(GraphicManager::GetInstance().GetWindow());
	}	
}
