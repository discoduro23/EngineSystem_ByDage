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
				SetTexture("GameHide");
			}
			//Mouse is inside button
			else
			{
				//Set mouse over sprite
				SetTexture("GameHideSelect");

			}
			
		}
		if (e.type == SDL_MOUSEBUTTONUP) {
			system("..\\..\\RELEASEGames\\HideAndWhere\\HideAndWhere.exe -P"); // As an example. Change [notepad] to any executable file //
		}

	}
	
}
