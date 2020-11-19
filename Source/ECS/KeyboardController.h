# pragma once
#include "../Game.hpp"
#include "ECS.h"
#include "Components.h"

class KeyboardController : public Component{
public:
	TransformComponent *transform;
	SpriteComponent *sprite;
	void init() override{
		transform = &entity->getComponent<TransformComponent>();
		sprite = &entity->getComponent<SpriteComponent>();
	}
	void update() override{
		if(Game::event.type == SDL_KEYDOWN){
			switch (Game::event.key.keysym.sym){
				//UP MOVE
				case SDLK_w:
					transform -> velocity.y = -1;
					sprite->Play("Back");
					break;
				case SDLK_UP:
					transform -> velocity.y = -1;
					sprite->Play("Back");
					break;
				//LEFT MOVE
				case SDLK_a:
					transform -> velocity.x = -1;
					sprite->Play("Left");
					break;
				case SDLK_LEFT:
					transform -> velocity.x = -1;
					sprite->Play("Left");
					break;
				//RIGHT MOVE
				case SDLK_d:
					transform -> velocity.x = 1;
					sprite->Play("Right");
					break;
				case SDLK_RIGHT:
					transform -> velocity.x = 1;
					sprite->Play("Right");
					break;
				//DOWN MOVE
				case SDLK_s:
					transform -> velocity.y = 1;
					sprite->Play("Front");
					break;
				case SDLK_DOWN:
					transform -> velocity.y = 1;
					sprite->Play("Front");
					break;
				default:
					break;
			}
		}
		if(Game::event.type == SDL_KEYUP){
			switch (Game::event.key.keysym.sym){
				//UP MOVE
				case SDLK_w:
					transform -> velocity.y = 0;
					sprite->Play("Idle");
					break;
				case SDLK_UP:
					transform -> velocity.y = 0;
					sprite->Play("Idle");
					break;
				//LEFT MOVE
				case SDLK_a:
					transform -> velocity.x = 0;
					sprite->Play("Idle");
					break;
				case SDLK_LEFT:
					transform -> velocity.x = 0;
					sprite->Play("Idle");
					break;
				//RIGHT MOVE
				case SDLK_d:
					transform -> velocity.x = 0;
					sprite->Play("Idle");
					break;
				case SDLK_RIGHT:
					transform -> velocity.x = 0;
					sprite->Play("Idle");
					break;
				//DOWN MOVE
				case SDLK_s:
					transform -> velocity.y = 0;
					sprite->Play("Idle");
					break;
				case SDLK_DOWN:
					transform -> velocity.y = 0;
					sprite->Play("Idle");
					break;
				//EXIT GAME
				case SDLK_ESCAPE:
					Game::isRunning = false;
				default:
					break;
			}
		}
	}
};
