#pragma once
#include "Object.h"
#include "InputManager.h"

class Head : public Object {
	
private:
	
	
public:
	Head(std::string name, float x, float y, int w, int h, SDL_Texture* texture = nullptr, int moveMode = 0, bool isCol = true)
		: Object(name, x, y, w, h, isCol, texture){};

	//Set Position
	void SetPosition(float x, float y) { mPosX = x; mPosY = y; };
	
	void Update() override;
};