//GAME

#pragma once
#include "Object.h"
#include <vector>
#include "Knight.h"
#include "Goblin.h"
#include <string>
#include "SoundManager.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "GraphicManager.h"
#include "PhysicsManager.h"

class GameManager :public Object {
private:
	int timerId = 0;

	//objects
	Knight* knight;
	Goblin* goblin;

	//score
	int score = 0;
	
public:
	GameManager(std::string name, int x = 0, int y = 0, int w = 0, int h = 0, SDL_Texture* texture = NULL) : Object(name, x, y, w, h, texture) {
		// Initialize the game manager
		
	}
		
	void Update();
	
	void Destroy();
	};