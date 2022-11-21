#include "Object.h"

class Dot : public Object {
public:
	Dot(std::string name, int x = 0, int y = 0, int w = 0, int h = 0, SDL_Texture* texture = NULL) : Object(name, x, y, w, h, texture) {}

	//The dimensions of the dot
	static const int DOT_WIDTH = 20;
	static const int DOT_HEIGHT = 20;

	//Maximum axis velocity of the dot
	static const int DOT_VEL = 10;

	//Initializes the variables
	Dot(int x = 0, int y = 0);

	//Moves the dot
	void move(int moveMode = 0);

	void Update();
};