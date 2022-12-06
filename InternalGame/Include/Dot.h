#pragma once
#include "Object.h"
#include "InputManager.h"
#include "GraphicManager.h"

class Dot : public Object {
private:
	//The velocity of the dot
	int mVelX = 10, mVelY = 10;

	int velMax = 10;

	int moveMode = 0;
	
public:
	Dot(std::string name, int x = 0, int y = 0, int w = 0, int h = 0, SDL_Texture* texture = NULL, int moveMode = 0) : Object(name, x, y, w, h, texture) {
		this->moveMode = moveMode;
	};

	//Moves the dot
	void move(int moveMode = 0);

	void Update();
};