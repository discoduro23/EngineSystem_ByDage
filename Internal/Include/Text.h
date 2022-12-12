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

	Text(std::string const& textName, std::string const& text, SDL_Color color, int x, int y, std::string const& font) 
		: textName(textName), text(text), color(color), x(x), y(y), font(font) {};

	std::string GetText() const { return text; }
	SDL_Color GetColor() const { return color; }
	int GetX() const { return x; }
	int GetY() const { return y; }
	std::string GetFont() const { return font; }
	std::string GetName() const { return textName; }

	void SetText(std::string const& text) { this->text = text; }
	void SetColor(SDL_Color color) { this->color = color; }
	void SetX(int x) { this->x = x; }
	void SetY(int y) { this->y = y; }
	void SetFont(std::string const& font) { this->font = font; }
	
	~Text() {};
};