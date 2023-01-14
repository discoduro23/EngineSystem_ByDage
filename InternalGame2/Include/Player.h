#pragma once
#include "Object.h"
#include "InputManager.h"
#include "GraphicManager.h"
#include "TimeManager.h"
#include "Head.h"

class Player : public Object {
private:
	float mVelX = 10, mVelY = -200;

	float velMaxX = 150;
	float velMaxY = 300;
	
	float impulse = 200;

	bool canMove = false;
	
	bool isOnMaxHeight = false;
	
	bool isDead = false;
	int deadTimer = 0;
	float deadTime = 3.6f;
	
	float gravity = 100.0f;
	
	Head* head = nullptr;
	
	//TimeManager* tM = TimeManager::GetInstancePtr();

public:
	Player(std::string name, SDL_Texture* texture = nullptr, SDL_Texture* particleTexture = nullptr, SDL_Texture* brightTexture = nullptr, int x = 0, int y = 0, int w = 0, int h = 0, int moveMode = 0, bool isCol = true)
		: Object(name, texture, particleTexture, brightTexture, x, y, w, h, isCol) {};

	//Moves the dot
	void Move();

	void DeadMove();

	void Update() override;
	
	void SetCanMove(bool canMove) { this->canMove = canMove; };
	bool GetCanMove() { return canMove; };
	
	void SetIsDead(bool isDead) { this->isDead = isDead; };
	bool GetIsDead() { return isDead; };

	float GetPosY() { return mPosY; };

	void AddVelY() { mVelY = -impulse; };
	float GetVelY() { return mVelY; };
	
	void SetGravity(float gravity) { this->gravity = gravity; };

	void SetHead(Head* head) { this->head = head; };
	Head* GetHead() { return head; };

	bool GetIsOnMaxHeight() { return isOnMaxHeight; };

};