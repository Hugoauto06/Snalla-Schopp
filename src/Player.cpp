#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../include/Player.hpp"
#include "../include/Entity.hpp"

Player::Player(Vector2f p_pos, SDL_Texture* p_tex)
:Entity { p_pos, p_tex }
{
	setPos(25, 25);
}