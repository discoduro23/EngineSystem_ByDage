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
	Goblin(std::string name, int x = 0, int y = 0, int w = 0, int h = 0, int moveMode = 0) : Object(name, x, y, w, h), moveMode(moveMode)  {	};

	//Moves the dot
	void move();

	void Update() override;
};