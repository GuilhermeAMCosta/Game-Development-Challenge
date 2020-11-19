#pragma once
#include "Components.h"
#include "SDL.h"
#include "../TextureManager.h"
#include "Animation.h"
#include <map>

class SpriteComponent : public Component{
private:
	TransformComponent *transform;
	SDL_Texture *texture;
	SDL_Rect srcRect, destRect;

	bool animated = false;
	int frames = 1;
	int speed = 100;


public:
	int aniIndex = 0;

	std::map<const char*, Animation> animations;

	SDL_RendererFlip spriteFlip = SDL_FLIP_NONE;

	SpriteComponent() = default;
	SpriteComponent(std::string id){
		setTex(id);
	}

	SpriteComponent(std::string id, bool isAnimated){
		
		animated = isAnimated;

		Animation idle = Animation(2, 2, 100);
		Animation back = Animation(0, 8, 100);
		Animation left = Animation(1, 8, 100);
		Animation front = Animation(2, 8, 100);
		Animation right = Animation(3, 8, 100);


		animations.emplace("Idle", idle);
		animations.emplace("Back", back);
		animations.emplace("Left", left);
		animations.emplace("Front", front);
		animations.emplace("Right", right);

		Play("Idle");

		setTex(id);
	}

	~SpriteComponent(){}

	void setTex(std::string id){
		texture = Game::assets->GetTexture(id);
	}

	void init() override{
		transform = &entity->getComponent<TransformComponent>();

		srcRect.x = srcRect.y = 0;
		srcRect.w = transform->widht;
		srcRect.h = transform->height;

	}

	void update() override{
		if(animated){
			srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks()/speed) % frames);
		}

		srcRect.y = aniIndex * transform->height;

		destRect.x = static_cast<int>(transform->position.x) - Game::camera.x;
		destRect.y = static_cast<int>(transform->position.y) - Game::camera.y;
		destRect.w = transform-> widht * transform->scale;
		destRect.h = transform-> height * transform->scale;
	}
	
	void draw() override{
		TextureManager::Draw(texture, srcRect, destRect, spriteFlip);
	}

	void Play(const char* aniName){
		frames = animations[aniName].frames;
		aniIndex = animations[aniName].index;
		speed = animations[aniName].speed;
	}
};