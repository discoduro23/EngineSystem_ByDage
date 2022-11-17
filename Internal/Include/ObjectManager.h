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

	Object& CreateObject(std::string name, int x = 0, int y = 0, int w = 0, int h = 0);

	void RemoveObject(Object* object);

	/*****************************************************************************/

};