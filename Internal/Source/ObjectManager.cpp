#include "ObjectManager.h"



void ObjectManager::Destroy()
{

}

void ObjectManager::Update()
{
	// Update the Objects
	for (int i = 0; i < mObjects.size(); i++)
	{
		mObjects[i]->Update();
	}
}


Object& ObjectManager::CreateObject(std::string name, int x = 0, int y = 0, int w = 0, int h = 0)
{

	Object* object = new Object(name, x, y, w, h);

	mObjects.push_back(object);
	return *object;
}


void ObjectManager::RemoveObject(Object* object)
{
	for (int i = 0; i < mObjects.size(); i++)
	{
		if (mObjects[i] == object)
		{
			mObjects.erase(mObjects.begin() + i);
			return;
		}
	}
}

