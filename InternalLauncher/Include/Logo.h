#pragma once
#include "Object.h"
#include <string>
#include "GraphicManager.h"
#include "TimeManager.h"
#include "InputManager.h"

class Logo : public Object{
	private:
		TimeManager* tM = nullptr;
		int timerId = 0;
		float frameTime = 0.05f;
		int currentFrame = 1;
		int MouseXOld = 0;
	public:
		Logo(std::string const& name, float x, float y, int w, int h)
			: Object(name, x, y, w, h) {};
		
		void Update() override;
};