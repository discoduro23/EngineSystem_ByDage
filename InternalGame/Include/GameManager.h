#pragma once
#include "Object.h"
#include <vector>
#include <EngineManager.h>

class GameManager :public Object {
private:
	static GameManager* m_instance;
	std::vector<Object*> m_objects;
	
public:
	GameManager(std::string name, int x = 0, int y = 0, int w = 0, int h = 0, SDL_Texture* texture = NULL) : Object(name, x, y, w, h, texture) {
		// Initialize the game manager
		

	}
	
	void init();
	
	void Update();
			
	void AddObject(Object* object);
	
	void RemoveObject(Object* object);
	
	void Destroy();
	};