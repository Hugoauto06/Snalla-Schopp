#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "../include/Player.hpp"
#include "../include/Entity.hpp"

Player::Player(Vector2f p_pos, SDL_Texture* p_tex)
:Entity { p_pos, p_tex }
{
	setPos(x, y);
}

void Player::Update()
{
	setPos(x, y);
	/*
		No esta funcionando por algun motivo
	*/
}
