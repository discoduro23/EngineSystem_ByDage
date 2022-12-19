#pragma once

#include "Singleton.h"
#include "SDL.h"
#include <vector>
#include <iostream>

#define JOYSTICK_DEAD_ZONE 8000

/**
Input Manager class
*/
class InputManager :public Singleton<InputManager> 
{
  /*****************************************************************************/
  friend class Singleton<InputManager>;
  /*****************************************************************************/

  
private:
  
  // Keyboard state
	const Uint8* mCurrentKeyStates;

  // Private constructor to avoid more than one instance
  InputManager() {
	  mCurrentKeyStates = SDL_GetKeyboardState(NULL);
  };

  std::vector<float> mousePosition();

  /*****************************************************************************/

public:
  
  void Update( void );

  bool GetKey( int scanCode );

  int GetMouseX(void);
  int GetMouseY(void);
  
  bool MouseLeftClick(void);
  bool MouseRightClick(void);
  /*****************************************************************************/

};