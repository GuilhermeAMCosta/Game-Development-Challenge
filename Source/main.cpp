#include "SDL.h"
#include <stdio.h>
#include "Game.hpp"

Game *game = nullptr;

int main(int argc, char* args[]){
	//Normal Fresh rate of monitors
	const int FPS = 60;
	const int frameDelay = 1000/FPS;
	//Control Frames
	Uint32 frameStart;
	int frameTime;

	game  = new Game();
	game->init("Run to FABAMAQ", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);

	//Game loop
	while(game->running()){	

		frameStart = SDL_GetTicks();

		game->update();
		game->render();
		game->handleEvents();

		frameTime = SDL_GetTicks() - frameStart;
		// Control Frame Rate
		if(frameDelay > frameTime){
			SDL_Delay(frameDelay - frameTime);
		}
	}
	game->clean();

	return 0;
}