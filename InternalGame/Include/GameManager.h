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
#include "SaveManager.h"
#include "GraphicManager.h"
#include "PhysicsManager.h"

class GameManager :public Object {
private:
	int timerId = 0;

	//objects
	Knight* knight = nullptr;
	Goblin* goblin = nullptr;

	//score
	int score = 0;

	//managers
	GraphicManager* grM = nullptr;
	TimeManager* tM = nullptr;
	ObjectManager* oM = nullptr;
	SoundManager* sM = nullptr;
	
public:
	GameManager(std::string const& name, int x = 0, int y = 0, int w = 0, int h = 0, SDL_Texture* texture = nullptr) : Object(name, x, y, w, h, texture) {
		// Initialize the game manager
		
	}
		
	void Update() override;
	
	void Destroy();
	
	//saveGameState
	void SaveGameState();
};