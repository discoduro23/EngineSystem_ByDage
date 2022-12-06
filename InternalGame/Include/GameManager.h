#pragma once
#include "Object.h"
#include <vector>
#include "Dot.h"

class GameManager :public Object {
private:
	
public:
	GameManager(std::string name, int x = 0, int y = 0, int w = 0, int h = 0, SDL_Texture* texture = NULL) : Object(name, x, y, w, h, texture) {
		// Initialize the game manager
		

	}
		
	void Update();
	
	void Destroy();
	};