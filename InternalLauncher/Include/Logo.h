#pragma once
#include "Object.h"
#include <string>

#include "TimeManager.h"

class Logo : public Object{
	private:
		TimeManager* tM = nullptr;
		int timerId = 0;
		float frameTime = 0.5f;
		int currentFrame = 0;

	public:
		Logo(std::string const& name, float x, float y, int w, int h)
			: Object(name, x, y, w, h) {};
		
		void Update() override;
};