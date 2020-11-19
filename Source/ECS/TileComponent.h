#pragma once

#include "../Vector2D.h"
#include "ECS.h"
#include "../TextureManager.h"
#include "../Game.hpp"


class TileComponent : public Component{
public:

	SDL_Texture * texture;
	SDL_Rect srcRect, destRect;
	Vector2D position;

	TileComponent() = default;

	~TileComponent(){
		SDL_DestroyTexture(texture);
	}

	TileComponent(int srcX, int srcY,
					 int xpos, int ypos,
					 	 int tsize, int tscale,
					 	 	std::string id){
		
		texture = Game::assets->GetTexture(id);

		position.x = static_cast<float>(xpos);
		position.y = static_cast<float>(ypos);

		srcRect.x = srcX;
		srcRect.y = srcY;
		//Size of Tiles
		srcRect.w = srcRect.h = tsize;

		destRect.x = xpos;
		destRect.y = ypos;
		//Scale of Tiles
		destRect.w = destRect.h = tscale * tsize;
	}

	void update() override{
		destRect.x = position.x - Game::camera.x;
		destRect.y = position.y - Game::camera.y;
	}

	void draw() override{
		TextureManager::Draw(texture, srcRect, destRect, SDL_FLIP_NONE);
	}

};