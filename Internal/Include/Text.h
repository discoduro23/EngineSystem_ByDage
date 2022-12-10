#pragma once

#include <SDL.h>
#include <stdio.h>
#include <string>
#include <iostream>

class Text {
protected:
	std::string textName = "";
	std::string text = "";
	SDL_Color color = { 0, 0, 0, 255 };
	int x = 0;
	int y = 0;
	std::string font = "";
	
public:
	Text() {};

	Text(std::string textName, std::string text, SDL_Color color, int x, int y, std::string font) {
		this->textName = textName;
		this->text = text;
		this->color = color;
		this->x = x;
		this->y = y;
		this->font = font;
	};

	std::string GetText() { return text; }
	SDL_Color GetColor() { return color; }
	int GetX() { return x; }
	int GetY() { return y; }
	std::string GetFont() { return font; }
	std::string GetName() { return textName; }

	void SetText(std::string text) { this->text = text; }
	void SetColor(SDL_Color color) { this->color = color; }
	void SetX(int x) { this->x = x; }
	void SetY(int y) { this->y = y; }
	void SetFont(std::string font) { this->font = font; }
	
	~Text();
};