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
	std::vector<Object*> mObjects = std::vector<Object*>();
	ObjectManager() {};
	/*****************************************************************************/

public:

	void Destroy();

	void Update();

	Object& CreateObject(std::string name, float x, float y, int w, int h, SDL_Texture* texture);

	void AddObject(Object* object) { mObjects.push_back(object);}

	Object* GetAObject(int index) { return mObjects[index]; };
	
	size_t GetObjectCount() { return mObjects.size(); }

	int GetObjectIndex(Object* object);

	void RemoveObject(Object* object);

	/*****************************************************************************/

};