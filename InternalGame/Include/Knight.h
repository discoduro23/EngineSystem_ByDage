#pragma once
#include "Object.h"
#include "InputManager.h"
#include "GraphicManager.h"
#include "TimeManager.h"

class Knight : public Object {
private:
	//The velocity of the dot
	int mVelX = 10, mVelY = 10;

	int velMax = 250;

	int moveMode = 0;

	int ChronoID = 0;

public:
	Knight(std::string name, int x = 0, int y = 0, int w = 0, int h = 0, int moveMode = 0) : Object(name, x, y, w, h), moveMode(moveMode) {	};

	//Moves the dot
	void move();

	void Update() override;
};