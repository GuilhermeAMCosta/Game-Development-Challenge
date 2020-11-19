#pragma once
#ifndef Game_hpp
#define Game_hpp

#include "SDL.h"
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

class AssetManager;
class ColliderComponent;
class Game {

public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int widht, int height, bool fullscreen);

	void update();
	void render();
	void clean();
	void handleEvents();

	bool running(){return isRunning;}
	bool paused(){return isPaused;}

	static SDL_Renderer* renderer;
	static SDL_Event event;
	static bool isRunning;
	static bool isPaused;
	static SDL_Rect camera;
	static AssetManager* assets;

	enum groupLabels : std::size_t{
	groupMap,
	groupPlayers,
	groupColliders,
	groupProjectiles,
	groupCars
};

private:
	int count = 0;
	SDL_Window *window;
};

#endif