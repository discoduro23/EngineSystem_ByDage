#pragma once
#include "Object.h"
#include "InputManager.h"
#include "GraphicManager.h"
#include "PhysicsManager.h"
#include "TimeManager.h"

class Dot : public Object {
private:
	//The velocity of the dot
	float mVelX = 5.0f, mVelY = 5.0f;

	float velMax = 600;

	int moveMode = 0;
	
public:
	Dot(std::string const& name, float x = 0, float y = 0, int w = 0, int h = 0, SDL_Texture* texture = nullptr, int moveMode = -1, bool isCollision = true, SDL_Texture* particleTexture = nullptr, SDL_Texture* brightTexture = nullptr)
		: Object(name, texture, particleTexture, brightTexture, x, y, w, h, isCollision), moveMode(moveMode) {
		AddTextureToArray("Idle", texture);
		SetTexture("Idle");
	};

	//Moves the dot
	void move(int moveMode = 0);

	void Update() override;
};