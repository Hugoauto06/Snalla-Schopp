/*
#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "Math.hpp"

class Player
{
public:
	Player(Vector2f p_pos, SDL_Texture* p_tex);
	void update();

	SDL_Texture* getTex();
	SDL_Rect getCurrentFrame();
private:
	Vector2f pos;
	Vector2f pos2;
	SDL_Texture* tex;
	SDL_Rect getCurrentFrame;
};
*/