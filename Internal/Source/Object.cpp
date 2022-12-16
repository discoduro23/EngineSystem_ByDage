#include "Object.h"


void Object::UpdateParticles()
{
	for (int i = 0; i < TOTAL_PARTICLES; i++)
	{
		if (mParticles[i]->IsDead())
		{
			delete mParticles[i];
			mParticles[i] = new Particle(mPosX, mPosY, mParticleTexture);
		}
		else
		{
			mParticles[i]->Update();
		}
	}
}

void Object::Update()
{
	//console log
	std::cout << "Update not implemented" << std::endl;
}

bool Object::coordIsInside(int xpos, int ypos) const
{
	bool inside = true;
	
	//Mouse is left of the button
	if (xpos < (int)mPosX)
	{
		inside = false;
	}
	//Mouse is right of the button
	else if (xpos > mPosX + mWidth)
	{
		inside = false;
	}
	//Mouse above the button
	else if (ypos < mPosY)
	{
		inside = false;
	}
	//Mouse below the button
	else if (ypos > mPosY + mHeight)
	{
		inside = false;
	}
	
	return inside;
}
