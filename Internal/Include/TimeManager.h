#pragma once

//Using SDL, SDL_image, standard IO, and strings
#include "SDL.h"
#include <SDL_image.h>
#include <stdio.h>
#include <string>

#include "Singleton.h"
#include <iostream>

#define MAX_TIMERS 10
#define MAX_CHRONOS 10

/**
Input Manager class
*/

class TimeManager :public Singleton<TimeManager>{
  /*****************************************************************************/
  friend class Singleton<TimeManager>;
  /*****************************************************************************/

private:

	Uint32 previousTime = 0;

	Uint32 currentTime = 0;
	Uint32 getCurrentTime() const { return currentTime; }

	// Delta time
	float mDeltaTime;

	// Timers
	bool mTimerActive[MAX_TIMERS];
	float mTimers[MAX_TIMERS];

	// Chronos
	bool mChronoActive[MAX_CHRONOS];
	float mChronos[MAX_CHRONOS];

	//Fps timer
	float mFPSTimer = 0.0f;
	int mFPStemp = 0;
	int mFPS = 0;

	// Private constructor to avoid more than one instance
	TimeManager();

	/*****************************************************************************/
	
public:

	bool Init(void);

	void Update(void);

	float GetDeltaTime(void);

	// Timers

	int StartTimer(float time);

	void StopTimer(int timer);

	float GetTimer(int timer);

	bool IsTimerActive(int timer);

	// Chronos

	int StartChrono();

	void StopChrono(int chrono);

	float GetChrono(int chrono);

	//FPS
	
	float GetFPStimer() const { return mFPSTimer; }
	void ResetFPStimer() { mFPSTimer = 0.0f; }
	int GetFPS() const { return mFPS; }
	void SumFPS() { mFPStemp++; }
	void CalculateFPS() { mFPS = mFPStemp; mFPStemp = 0; }

	//Destructor
	~TimeManager() = default;

	/*****************************************************************************/

};
