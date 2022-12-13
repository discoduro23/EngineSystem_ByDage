#include "Button.h"

void Button::handleevent()
{
	SDL_Event e;
	while (SDL_PollEvent(&e) != 0) {
		//If mouse event happened
		if (e.type == SDL_MOUSEMOTION )
		{
			//Get mouse position
			int x, y;
			SDL_GetMouseState(&x, &y);

			//Check if mouse is in button
			bool inside = true;

			//Mouse is left of the button
			if (x < GetX())
			{
				inside = false;
			}
			//Mouse is right of the button
			else if (x > GetX() + mWidth)
			{
				inside = false;
			}
			//Mouse above the button
			else if (y < GetY())
			{
				inside = false;
			}
			//Mouse below the button
			else if (y > GetY() + mHeight)
			{
				inside = false;
			}

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
			
		}
		if (e.type == SDL_MOUSEBUTTONUP && isInZone){
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
	
}
