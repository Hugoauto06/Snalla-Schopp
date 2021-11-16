#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../include/Math.hpp"
#include "../include/Entity.hpp"

class Player : public Entity
{
public:
	Player(Vector2f p_pos, SDL_Texture* p_tex);
private:
};

/*
	Player.hpp cuenta con las mismas funciones que Entity.hpp,
	este hereda todo en la class de Entity.hpp, asi que setPos,
	getPos y otras deberian funcionar.


*/