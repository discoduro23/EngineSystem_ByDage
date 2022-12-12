#pragma once
#include "Object.h"
#include "InputManager.h"
#include "GraphicManager.h"
#include "TimeManager.h"
#include <SDL.h>
#include <Windows.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

enum lbuttonsprite
{
	button_sprite_mouse_out = 0,
	button_sprite_mouse_over_motion = 1,
	button_sprite_mouse_down = 2,
	button_sprite_mouse_up = 3,
	button_sprite_total = 4
};

class Button : public Object {
private:
	//currently used global sprite
	lbuttonsprite mcurrentsprite;

public:
	Button(std::string name, float x = 0, float y = 0, int w = 0, int h = 0)
		: Object(name, x, y, w, h) {};

	void Update() { handleevent(); };
	
	//handles mouse event
	void handleevent();

};