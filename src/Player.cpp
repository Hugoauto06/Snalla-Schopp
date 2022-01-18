#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "Player.hpp"
#include "Entity.hpp"
#include "Math.hpp"

Player::Player(Vector2f p_pos, SDL_Texture* p_tex)
:Entity { p_pos, p_tex }
{
	setPos(x, y);
}

void Player::Update()
{
	setPos(x, y);
	std::cout << x << std::endl;

	/*
		No esta funcionando por algun motivo
	*/
}
