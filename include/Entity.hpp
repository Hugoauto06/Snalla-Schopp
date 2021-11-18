#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../include/Math.hpp"

class Entity
{
public:
	Entity(Vector2f p_pos, SDL_Texture* p_tex);
	SDL_Texture* getTex();
	SDL_Rect getCurrentFrame();

	Vector2f& getPos()
	{
		return pos;
	}

	void setPos(float s_x, float s_y)
	{
		pos = Vector2f(s_x, s_y);
	}
private:
	Vector2f pos;
	SDL_Rect currentFrame;
	SDL_Texture* tex;
};