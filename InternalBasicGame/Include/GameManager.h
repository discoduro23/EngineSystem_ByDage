//BASIC GAME

#pragma once
#include "Object.h"
#include <vector>
#include <string>
#include "Dot.h"

#include "SoundManager.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "GraphicManager.h"

class GameManager :public Object {
public:
	GameManager(std::string const& name, int x = 0, int y = 0, int w = 0, int h = 0, SDL_Texture* texture = nullptr) : Object(name, x, y, w, h, texture) {};
		
	void Update() override;
	};