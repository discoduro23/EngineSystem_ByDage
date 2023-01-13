#pragma once
#include "Object.h"
#include "TimeManager.h"
#include "GraphicManager.h"

class Platform : public Object {
private:
	int mVelX = 100, mVelY = 0;
	int velMax = 200;
	int moveMode = 0;
	
	bool canMove = false;
	int direction = 1;
	
public:
	Platform(std::string name, float x, float y, int w, int h, SDL_Texture* texture = nullptr, int moveMode = 0, bool isCol = true)
		: Object(name, x, y, w, h, isCol, texture), moveMode(moveMode) {};

	//Moves the dot
	void move();

	void Update() override;
	
	void SetVelY(int velY) { mVelY = velY; };
};