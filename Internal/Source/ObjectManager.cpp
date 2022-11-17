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

void ObjectManager::AddObject(Object* object)
{
	mObjects.push_back(object);
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

