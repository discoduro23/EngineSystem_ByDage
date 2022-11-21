#pragma once

//Using SDL, SDL_image, standard IO, and strings
#include "SDL.h"
#include <SDL_image.h>
#include <stdio.h>
#include <string>

#include "Singleton.h"
#include "LTimer.h"
#include <iostream>

/**
Input Manager class
*/

class TimeManager :public Singleton<TimeManager>{
  /*****************************************************************************/
  friend class Singleton<TimeManager>;
  /*****************************************************************************/

private:

	// Keyboard state
	LTimer mTimer;

	// Private constructor to avoid more than one instance
	TimeManager() {};

	/*****************************************************************************/
	
public:

	void Update(void);

	float GetDeltaTime(void);

	/*****************************************************************************/

};
