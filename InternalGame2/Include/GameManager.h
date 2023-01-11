//GAME2

#pragma once
#include "Object.h"
#include <vector>
#include <string>
#include "SoundManager.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "SaveManager.h"
#include "GraphicManager.h"
#include "PhysicsManager.h"
#include "SaveManager.h"
#include "Player.h"

class GameManager :public Object {
private:
	int timerId = 0;

	//objects


	//score
	int score = 0;

	//managers
	GraphicManager* grM = nullptr;
	TimeManager* tM = nullptr;
	ObjectManager* oM = nullptr;
	SoundManager* sM = nullptr;


public:
	GameManager(std::string const& name, int x = 0, int y = 0, int w = 0, int h = 0, SDL_Texture* texture = nullptr)
		: Object(name, x, y, w, h, texture) {}

	void Update() override;

	void Destroy();

	//saveGameState
	void SaveGameState();

	//loadGameState
	void LoadGameState();
};