#include "Head.h"

void Head::Update()
{
	//change head texture based on imput 1 to 7
	if (InputManager::GetInstancePtr()->GetKey(SDL_SCANCODE_1))
		SetTexture("amoHead0");
	else if (InputManager::GetInstancePtr()->GetKey(SDL_SCANCODE_2))
		SetTexture("amoHead1");
	else if (InputManager::GetInstancePtr()->GetKey(SDL_SCANCODE_3))
		SetTexture("amoHead2");
	else if (InputManager::GetInstancePtr()->GetKey(SDL_SCANCODE_4))
		SetTexture("amoHead3");
	else if (InputManager::GetInstancePtr()->GetKey(SDL_SCANCODE_5))
		SetTexture("amoHead4");
	else if (InputManager::GetInstancePtr()->GetKey(SDL_SCANCODE_6))
		SetTexture("amoHead5");
	else if (InputManager::GetInstancePtr()->GetKey(SDL_SCANCODE_7))
		SetTexture("amoHead6");
}
