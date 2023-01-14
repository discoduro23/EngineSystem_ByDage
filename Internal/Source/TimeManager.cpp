#include "TimeManager.h"

TimeManager::TimeManager()
{
    mDeltaTime = 0;

    // Initialize timers
    for (int i = 0; i < MAX_TIMERS; i++) {
        mTimerActive[i] = false;
        mTimers[i] = 0.0f;
    }

    // Initialize chronos
    for (int i = 0; i < MAX_CHRONOS; i++) {
        mChronoActive[i] = false;
        mChronos[i] = 0.0f;
    }
}

bool TimeManager::Init(void){
    mDeltaTime = 0.0f;
    previousTime = SDL_GetTicks();

    if(previousTime == 0){
        std::cout << "SDL_GetTicks() failed" << std::endl;
        return false;
    }

    for(int i = 0; i < MAX_TIMERS; i++){
        mTimerActive[i] = false;
        mTimers[i] = 0.0f;
    }

    for(int i = 0; i < MAX_CHRONOS; i++){
        mChronoActive[i] = false;
        mChronos[i] = 0.0f;
    }
    
    return true;
}

float TimeManager::GetDeltaTime(void){
    return mDeltaTime;
}

void TimeManager::Update(void){

    currentTime = SDL_GetTicks();
    mDeltaTime = (currentTime - previousTime) / 1000.0f;
    previousTime = currentTime;

    //Timer stuff
    for(int i = 0; i < MAX_TIMERS; i++){
        if(mTimerActive[i]){

            
            mTimers[i] -= mDeltaTime;
            if(mTimers[i] <= 0.0f){
                mTimerActive[i] = false;
                mTimers[i] = 0.0f;
            }
        }
    }

    //chrono stuff
    for (int i = 0; i < MAX_CHRONOS; i++) {
        if(mChronoActive[i]){
            mChronos[i] += mDeltaTime;
        }
    }
	
	//fps stuff
	mFPSTimer += mDeltaTime;
}

// Timers

	int TimeManager::StartTimer(float time){
        for(int i = 0; i < MAX_TIMERS; i++){
            if(!mTimerActive[i]){
                mTimerActive[i] = true;
                mTimers[i] = time;
                return i;
            }
        }

        std::cout << "No more timers available" << std::endl;
        return -1;
        
    }

	void TimeManager::StopTimer(int timer){
        if(timer >= 0 && timer < MAX_TIMERS){
            mTimerActive[timer] = false;
            mTimers[timer] = 0.0f;
        }
        else {
            std::cout << "Invalid timer" << std::endl;
        }

    }

	float TimeManager::GetTimer(int timer){
        if(timer >= 0 && timer < MAX_TIMERS){
            return mTimers[timer];
        }
        else {
            std::cout << "Invalid timer" << std::endl;
            return -1.0f;
        }

    }

	bool TimeManager::IsTimerActive(int timer){
        if(timer >= 0 && timer < MAX_TIMERS){
            return mTimerActive[timer];
        }
        else {
            std::cout << "Invalid timer" << std::endl;
            return false;
        }

    }

	// Chronos

	int TimeManager::StartChrono(){
        for(int i = 0; i < MAX_CHRONOS; i++){
            if(!mChronoActive[i]){
                mChronoActive[i] = true;
                mChronos[i] = 0.0f;
                return i;
            }
        }

        std::cout << "No more chronos available" << std::endl;
        return -1;

    }

	void TimeManager::StopChrono(int chrono){
        if(chrono >= 0 && chrono < MAX_CHRONOS){
            mChronoActive[chrono] = false;
            mChronos[chrono] = 0.0f;
        }
        else {
            std::cout << "Invalid chrono" << std::endl;
        }


    }

	float TimeManager::GetChrono(int chrono){
        if(chrono >= 0 && chrono < MAX_CHRONOS){
            return mChronos[chrono];
        }
        else {
            std::cout << "Invalid chrono" << std::endl;
            return -1.0f;
        }


    }

   
