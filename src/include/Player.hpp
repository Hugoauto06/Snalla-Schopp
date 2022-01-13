#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Math.hpp"
#include "Entity.hpp"

class Player : public Entity
{
public:
	Player(Vector2f p_pos, SDL_Texture* p_tex);

	void Update();

	void setX(float p_x)
	{
		x = p_x;
	}
	void setY(float p_y)
	{
		y = p_y;
	}

	float getX()
	{
		return x;
	}
	float getY()
	{
		return y;
	}
private:
	float x = 0, y = 1;
};

/*
	Player.hpp cuenta con las mismas funciones que Entity.hpp,
	este hereda todo en la class de Entity.hpp, asi que setPos,
	getPos y otras deberian funcionar.
*/
