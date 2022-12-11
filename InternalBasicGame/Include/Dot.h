#pragma once
#include "Object.h"
#include "InputManager.h"
#include "GraphicManager.h"
#include "PhysicsManager.h"
#include "TimeManager.h"

class Dot : public Object {
private:
	//The velocity of the dot
	float mVelX = 10.0f, mVelY = 10.0f;

	float velMax = 600;

	int moveMode = 0;
	
public:
	Dot(std::string const& name, int x = 0, int y = 0, int w = 0, int h = 0, SDL_Texture* texture = NULL, int moveMode = -1) : Object(name, x, y, w, h, texture), moveMode(moveMode) {
		AddTextureToArray("Idle", texture);
		SetTexture("Idle");
	};

	//Moves the dot
	void move(int moveMode = 0);

	void Update() override;
};