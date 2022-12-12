#pragma once

#include "SDL.h"
#include "Singleton.h"
#include <stdio.h>
#include <string>
#include <vector>

#include "ObjectManager.h"

class PhysicsManager : public Singleton<PhysicsManager>
{
	/*****************************************************************************/
	friend class Singleton<PhysicsManager>;
	/*****************************************************************************/

private:

    float gravity = 9.8f; 

	// Private constructor to avoid more than one instance
	PhysicsManager() {};
	/*****************************************************************************/

public:

	//verify a collision betweeN two rectangles
	bool CheckCollision(SDL_Rect a, SDL_Rect b);

    //verify a collision between all the rectangles in a vector
	bool CheckCollisionAll(SDL_Rect a, std::string name);

	//Get distance between two points
	float GetDistance(float x1, float y1, float x2, float y2);
	
    float getGravity() const { return gravity; }

};