#pragma once
#include "Object.h"
#include "InputManager.h"
#include "GraphicManager.h"
#include "TimeManager.h"

class Goblin : public Object {
private:
	//The velocity of the dot
	float mVelX = 10, mVelY = 10;

	float velMax = 250;

	int moveMode = 0;

	int ChronoID = 0;

public:
	Goblin(std::string name, SDL_Texture* texture = nullptr, SDL_Texture* particleTexture = nullptr, SDL_Texture* brightTexture = nullptr, int x = 0, int y = 0, int w = 0, int h = 0, int moveMode = 0, bool isCol = true)
		: Object(name, texture, particleTexture, brightTexture, x, y, w, h, isCol), moveMode(moveMode) {};

	//Moves the dot
	void move();

	void Update() override;
};