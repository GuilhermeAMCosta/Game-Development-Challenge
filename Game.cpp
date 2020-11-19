#include "Game.hpp"
#include "TextureManager.h"
#include "Map.h"
#include "ECS/Components.h"
#include "Vector2D.h"
#include "Collision.h"
#include "AssetManager.h"
#include <sstream>

Map* map;
Manager manager;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

SDL_Rect Game::camera = {0,0,800,640};

AssetManager* Game::assets = new AssetManager(&manager);

bool Game::isRunning = false;

auto& player(manager.addEntity());

//Screen Information
auto& creditsIn(manager.addEntity());
auto& creditsOut(manager.addEntity());
auto& tPlayed(manager.addEntity());

int NcreditsIn = 0;
int NcreditsOut = 0;
int TimesPlayed = 0;

int count = 0;

bool Pause = true;

Game::Game(){}

Game::~Game(){}

void Game::init(const char *title, int xpos, int ypos, int widht, int height, bool fullscreen){
	//Fullscreen or not
	int flags = 0;
	if(fullscreen){
		flags = SDL_WINDOW_FULLSCREEN;
	}
	//Check Subsystems 
	if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
		std::cout << "Subsystems OK!" << std::endl;
		window = SDL_CreateWindow(title, xpos, ypos, widht, height, flags);
		
		//Check Window Created
		if(window)
			std::cout << "Window Created!" << std::endl;
		renderer = SDL_CreateRenderer(window, -1, 0);
		
		//Check Renderer Created
		if(renderer)
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer Created!" << std::endl;
 		isRunning = true;

 		if(TTF_Init() == -1){
 			std::cout << "Error: SDL_TTF" << std::endl;
 		}

 		//Assets Files
 		assets->AddTexture("terrain", "Assets/Tileset.png");
 		assets->AddTexture("player", "Assets/Sprite.png");
 		assets->AddTexture("projectile", "Assets/virus.png");
 		assets->AddTexture("car1", "Assets/sedan_E.png");
 		assets->AddTexture("car2", "Assets/van_W.png");
 		assets->AddTexture("car3", "Assets/taxi_E.png");
 		assets->AddTexture("car4", "Assets/police_W.png");


 		//Font UI
 		assets->AddFont("fonte", "Assets/Fonte.ttf", 16);

 		//Map Creation Details
 		map = new Map("terrain", 2, 32);

 		//ECS Implementation
 		map->LoadMap("Assets/map.map", 28, 16);

 		player.addComponent<TransformComponent>(100.0f, 300.0f, 64 , 64, 1);
 		player.addComponent<SpriteComponent>("player", true);
 		player.addComponent<KeyboardController>();
 		player.addComponent<ColliderComponent>("player");
 		player.addGroup(groupPlayers);

 		SDL_Color white = {255, 255, 255, 255};

 		//Screen Information
 		creditsIn.addComponent<UILabel>(10, 10, "", "fonte", white);
 		creditsOut.addComponent<UILabel>(10, 30, "", "fonte", white);
 		tPlayed.addComponent<UILabel>(10, 50, "", "fonte", white);


 		//Moving Objects
 		
		//assets->CreateProjectile(Vector2D(200, 300), Vector2D(2,1),	1000, 1, "car");

		//Every Time that Objects finishes their moviment Times Played will be incremented, like waves
		TimesPlayed = TimesPlayed + 1;
	}
	else{
		isRunning = false;
	}
}

//Group of Objects
auto& tiles(manager.getGroup(Game::groupMap));
auto& players(manager.getGroup(Game::groupPlayers));
auto& colliders(manager.getGroup(Game::groupColliders));
auto& projectile(manager.getGroup(Game::groupProjectiles));
auto& car(manager.getGroup(Game::groupCars));

void Game::handleEvents(){
	SDL_PollEvent(&event);
	switch(event.type){
		case SDL_QUIT:
			isRunning = false;
			break;
		default:
			break;
	}
}
//Function to Keep Game Up to Date
void Game::update(){
		//Regenerate Objects
		count ++;
		if(count % 300 == 0){
			
			assets->CreateProjectile(Vector2D(200, 0), Vector2D(0,1),	1000, 1, "projectile");
			assets->CreateProjectile(Vector2D(350, 0), Vector2D(0,1),	1000, 1, "projectile");
			assets->CreateProjectile(Vector2D(550, 0), Vector2D(0,1),	1000, 1, "projectile");
			assets->CreateProjectile(Vector2D(700, 0), Vector2D(0,1),	1000, 1, "projectile");
			assets->CreateProjectile(Vector2D(850, 0), Vector2D(0,1),	1000, 1, "projectile");

			assets->CreateProjectile(Vector2D(200, 100), Vector2D(0,1),	1000, 1, "projectile");
			assets->CreateProjectile(Vector2D(350, 100), Vector2D(0,1),	1000, 1, "projectile");
			assets->CreateProjectile(Vector2D(500, 100), Vector2D(0,1),	1000, 1, "projectile");
			assets->CreateProjectile(Vector2D(650, 100), Vector2D(0,1),	1000, 1, "projectile");
			assets->CreateProjectile(Vector2D(800, 100), Vector2D(0,1),	1000, 1, "projectile");
			assets->CreateProjectile(Vector2D(950, 100), Vector2D(0,1),	1000, 1, "projectile");
			assets->CreateProjectile(Vector2D(1100, 100), Vector2D(0,1),	1000, 1, "projectile");
			assets->CreateProjectile(Vector2D(1250, 100), Vector2D(0,1),	1000, 1, "projectile");
			assets->CreateProjectile(Vector2D(1400, 100), Vector2D(0,1),	1000, 1, "projectile");

			assets->CreateProjectile(Vector2D(200, 1000), Vector2D(0,-1),	1000, 1, "projectile");
			assets->CreateProjectile(Vector2D(350, 1000), Vector2D(0,-1),	1000, 1, "projectile");
			assets->CreateProjectile(Vector2D(500, 1000), Vector2D(0,-1),	1000, 1, "projectile");
			assets->CreateProjectile(Vector2D(650, 1000), Vector2D(0,-1),	1000, 1, "projectile");
			assets->CreateProjectile(Vector2D(800, 1000), Vector2D(0,-1),	1000, 1, "projectile");
			assets->CreateProjectile(Vector2D(950, 1000), Vector2D(0,-1),	1000, 1, "projectile");
			assets->CreateProjectile(Vector2D(1100, 1000), Vector2D(0,-1),	1000, 1, "projectile");
			assets->CreateProjectile(Vector2D(1250, 1000), Vector2D(0,-1),	1000, 1, "projectile");
			assets->CreateProjectile(Vector2D(1400, 1000), Vector2D(0,-1),	1000, 1, "projectile");

			assets->CreateProjectile(Vector2D(0, 100), Vector2D(1,0),	1000, 1, "projectile");
			assets->CreateProjectile(Vector2D(0, 200), Vector2D(1,0),	1000, 1, "projectile");
			assets->CreateProjectile(Vector2D(0, 600), Vector2D(1,0),	1000, 1, "projectile");	
			assets->CreateProjectile(Vector2D(0, 750), Vector2D(1,0),	1000, 1, "projectile");	
			assets->CreateProjectile(Vector2D(0, 900), Vector2D(1,0),	1000, 1, "projectile");
			assets->CreateProjectile(Vector2D(0, 1050), Vector2D(1,0),	1000, 1, "projectile");
			assets->CreateProjectile(Vector2D(0, 1200), Vector2D(1,0),	1000, 1, "projectile");	

			assets->CreateProjectile(Vector2D(1000, 100), Vector2D(-1,0),	1000, 1, "projectile");
			assets->CreateProjectile(Vector2D(1000, 200), Vector2D(-1,0),	1000, 1, "projectile");
			assets->CreateProjectile(Vector2D(1000, 600), Vector2D(-1,0),	1000, 1, "projectile");	
			assets->CreateProjectile(Vector2D(1000, 750), Vector2D(-1,0),	1000, 1, "projectile");	
			assets->CreateProjectile(Vector2D(1000, 900), Vector2D(-1,0),	1000, 1, "projectile");
			assets->CreateProjectile(Vector2D(1000, 1050), Vector2D(-1,0),	1000, 1, "projectile");
			assets->CreateProjectile(Vector2D(1000, 1200), Vector2D(-1,0),	1000, 1, "projectile");	

			assets->CreateProjectile(Vector2D(300, 0), Vector2D(1,1),	1000, 1, "projectile");	
			assets->CreateProjectile(Vector2D(500, 0), Vector2D(1,1),	1000, 1, "projectile");	
			assets->CreateProjectile(Vector2D(700, 0), Vector2D(1,1),	1000, 1, "projectile");	
			assets->CreateProjectile(Vector2D(900, 0), Vector2D(1,1),	1000, 1, "projectile");	
			assets->CreateProjectile(Vector2D(1100, 0), Vector2D(1,1),	1000, 1, "projectile");	
			assets->CreateProjectile(Vector2D(1300, 0), Vector2D(1,1),	1000, 1, "projectile");	

			assets->CreateProjectile(Vector2D(1200, 0), Vector2D(-1,1),	1000, 1, "projectile");
			assets->CreateProjectile(Vector2D(1400, 0), Vector2D(-1,1),	1000, 1, "projectile");
			assets->CreateProjectile(Vector2D(800, 0), Vector2D(-1,1),	1000, 1, "projectile");


			// assets->CreateProjectile(Vector2D(0, 540), Vector2D(1,-1),	1000, 1, "projectile");
			// assets->CreateProjectile(Vector2D(600, 0), Vector2D(0,1),	1000, 1, "projectile");
			// assets->CreateProjectile(Vector2D(300, 300), Vector2D(1,1),	1000, 1, "projectile");

			// assets->CreateProjectile(Vector2D(0, 700), Vector2D(1,-1),	1000, 1, "projectile");
			// assets->CreateProjectile(Vector2D(800, 0), Vector2D(0,1),	1000, 1, "projectile");
			// assets->CreateProjectile(Vector2D(300, 300), Vector2D(1,1),	1000, 1, "projectile");

			// assets->CreateProjectile(Vector2D(0, 800), Vector2D(0,-1),	1000, 1, "projectile");
			// assets->CreateProjectile(Vector2D(800, 0), Vector2D(0,1),	1000, 1, "projectile");
			// assets->CreateProjectile(Vector2D(300, 300), Vector2D(1,1),	1000, 1, "projectile");

		}
		if(count % 400 != count % 500){
			if(count % 400 == 0){
				assets->CreateProjectile(Vector2D(0, 450), Vector2D(1,0),	1000, 1, "car1");
				assets->CreateProjectile(Vector2D(800, 550), Vector2D(-1,0),	1000, 1, "car2");
			}
			if(count % 500 == 0){
				assets->CreateProjectile(Vector2D(0, 450), Vector2D(1,0),	1000, 1, "car3");
				assets->CreateProjectile(Vector2D(800, 550), Vector2D(-1,0),	1000, 1, "car4");
			}
		}

		SDL_Rect playerCol = player.getComponent<ColliderComponent>().collider;
		Vector2D playerPos = player.getComponent<TransformComponent>().position;

		//Input control of screen info
		if(Game::event.type == SDL_KEYDOWN){
			switch (Game::event.key.keysym.sym){
				//CREDIT IN
				case SDLK_i:
					NcreditsIn = NcreditsIn + 1;
					break;
				//CREDIT OUT
				case SDLK_o:
					if(NcreditsIn > 0){
						NcreditsIn = NcreditsIn - 1;
						NcreditsOut = NcreditsOut + 1;
					}
					if(NcreditsIn < 0){
						NcreditsIn = 0;
					}
					break;
				//PAUSE
				case SDLK_SPACE:
					if(Pause == true){
						Pause = false;
					}
					else{
						Pause = true;
					}
					break;

			}
		}
		if(!Pause){
		//Display Information on Screen
		std::stringstream s0, s1, s2;
		s0 << "CREDITS IN: " << NcreditsIn;
		creditsIn.getComponent<UILabel>().SetLabelText(s0.str(), "fonte");
		s1 << "CREDITS OUT: " << NcreditsOut;
		creditsOut.getComponent<UILabel>().SetLabelText(s1.str(), "fonte");
		s2 << "TIMES PLAYED: " << TimesPlayed;
		tPlayed.getComponent<UILabel>().SetLabelText(s2.str(), "fonte");

		//If dont have credits, game wont update
		if(NcreditsIn > 0){

			manager.update();
			manager.refresh();

			//Update Camera Position (Following Player)
			camera.x = player.getComponent<TransformComponent>().position.x - 400;
			camera.y = player.getComponent<TransformComponent>().position.y - 320;

			//Player Collides with Bounds of Map
			for(auto& c : colliders){
				SDL_Rect cCol = c -> getComponent<ColliderComponent>().collider;
				if(Collision::AABB(cCol, playerCol)){
					//Back Force to the Last Position
					player.getComponent<TransformComponent>().position = playerPos;
				}
			}
			//Player Collides with COVID
			for(auto& g : projectile){
				if(Collision::AABB(player.getComponent<ColliderComponent>().collider,
				 					g->getComponent<ColliderComponent>().collider)){
					std::cout << "Hit Player!" << std::endl;
					g->destroy();
					NcreditsIn --;
					TimesPlayed ++;
				}
			}
			//Check Camera Bounds
			if(camera.x < 0)
				camera.x = 0;
			if(camera.y < 0)
				camera.y = 0;
			if(camera.x > camera.w)
				camera.x = camera.w;
			if(camera.y > camera.h)
				camera.y = camera.h;
		}
	}

}


void Game::render(){

	//Render Sequence of Group Objects
	SDL_RenderClear(renderer);
	
	for (auto& t : tiles){
		t->draw();
	}
	for (auto& p : players){
		p->draw();
	}
	for (auto& g : projectile){
		g->draw();
	}

	creditsIn.draw();
	creditsOut.draw();
	tPlayed.draw();

	SDL_RenderPresent(renderer);
}

void Game::clean(){
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned!" << std::endl;
}

