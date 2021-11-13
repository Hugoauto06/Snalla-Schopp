#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include <string>

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Player.hpp"

bool gameRunning = true;

/* Initialize Variables */
RenderWindow window("Game v1.0", 1280, 720);
SDL_Texture* grassTexture;
SDL_Texture* playerTexture;
std::vector<Entity> entities;

/* Init Values */
void init()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);

	grassTexture = window.loadTexture("res/img/ground_grass_1.png");
	playerTexture = window.loadTexture("res/img/player.png");
}

void inputHandler()
{
	const Uint8 *state = SDL_GetKeyboardState(NULL);

	if (state[SDL_SCANCODE_F11])
	{
		
	}
}

int main(int argc, char *args[])
{
	init();

	//Player player(Vector2f(32, 255), playerTexture);

	for(int i = 0; i < 40; i+=1)
	{
		Entity ground(Vector2f(i * 32, 688), grassTexture);
		ground.setPos(x , );

		entities.push_back(ground);
	}

	/* Game Loop */
	SDL_Event event;

	while(gameRunning)
	{
		inputHandler();

		/* Window Events (closing the window) */
		while(SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				gameRunning = false;
			}
		}

		window.clear();
		
		// For every Entity in entities, render
		for (Entity& ent : entities)
		{
			window.render(ent);
		}

		window.display();
	}

	window.cleanUp();
	SDL_Quit();

	return 0;
}