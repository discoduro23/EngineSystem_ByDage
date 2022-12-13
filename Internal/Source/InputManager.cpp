#include "InputManager.h"

void InputManager::Update(void)
{
  mCurrentKeyStates = SDL_GetKeyboardState(NULL);
}

bool InputManager::GetKey(int scanCode)
{
	return mCurrentKeyStates[scanCode] != 0;
}

int InputManager::GetMouseX(void)
{
	int x = 0;
	int y = 0;
	SDL_GetMouseState(&x, &y);
	return x;
}

int InputManager::GetMouseY(void)
{
	int x = 0;
	int y = 0;
	SDL_GetMouseState(&x, &y);
	return y;
}

bool InputManager::MouseLeftClick(void)
{
	return SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT);
}

bool InputManager::MouseRightClick(void)
{
	return SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_RIGHT);
}



//SDL_SCANCODE_UP
//SDL_SCANCODE_DOWN
//SDL_SCANCODE_LEFT
//SDL_SCANCODE_RIGHT

