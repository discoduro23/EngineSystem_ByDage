#include "PhysicsManager.h"

bool PhysicsManager::CheckCollision(SDL_Rect a, SDL_Rect b)
{
	//The sides of the rectangles
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	//Calculate the sides of rect A
	leftA = a.x;
	rightA = a.x + a.w;
	topA = a.y;
	bottomA = a.y + a.h;

	//Calculate the sides of rect B
	leftB = b.x;
	rightB = b.x + b.w;
	topB = b.y;
	bottomB = b.y + b.h;

	//If any of the sides from A are outside of B
	if (bottomA <= topB)
	{
		return false;
	}

	if (topA >= bottomB)
	{
		return false;
	}

	if (rightA <= leftB)
	{
		return false;
	}

	if (leftA >= rightB)
	{
		return false;
	}

	//If none of the sides from A are outside B
	return true;
	
}

bool PhysicsManager::CheckCollisionAll(SDL_Rect a, std::string name)
{
    //This will be used to check if the player is colliding with the objects that have the bool true in isCollider
	bool isColliding = false;
    ObjectManager* oM = ObjectManager::GetInstancePtr();

    for(int i = 0; i < oM->GetObjectCount(); i++)
    {
		if (oM->GetAObject(i)->isCollision() && oM->GetAObject(i)->GetName() != name)
		{
			if (CheckCollision(a, oM->GetAObject(i)->GetRect()))
			{
				isColliding = true;
			}
		}
    }
	return isColliding;
}

float PhysicsManager::GetDistance(float x1, float y1, float x2, float y2)
{
	float xDistance = x2 - x1;
	float yDistance = y2 - y1;

	return sqrt((xDistance * xDistance) + (yDistance * yDistance));
}
