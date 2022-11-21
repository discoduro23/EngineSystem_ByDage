#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <Object.h>
#include <iostream>
#include <Singleton.h>
#include <vector>


/**
Input Manager class
*/
class ObjectManager :public Singleton<ObjectManager> {
	/*****************************************************************************/
	friend class Singleton<ObjectManager>;
	/*****************************************************************************/
private:
	std::vector<Object*> mObjects;
	ObjectManager() {};
	/*****************************************************************************/

public:

	void Destroy();

	void Update();

	Object& CreateObject(std::string name, int x, int y, int w, int h, SDL_Texture* texture);

	void AddObject(Object* object) { mObjects.push_back(object);}

	Object* GetObject(int index) { return mObjects[index]; };
	
	int GetObjectCount() { return mObjects.size(); }

	void RemoveObject(Object* object);

	/*****************************************************************************/

};