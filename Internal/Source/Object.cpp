#include "Object.h"

Object::~Object()
{
	for (std::map<std::string, SDL_Texture*>::iterator it = mTextureArray.begin(); it != mTextureArray.end(); ++it)
	{
		SDL_DestroyTexture(it->second);
	}
}



void Object::Update()
{
	//console log
	std::cout << "Update not implemented" << std::endl;
}
