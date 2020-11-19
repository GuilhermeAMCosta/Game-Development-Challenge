#pragma once

#include <map>
#include <string>
#include "TextureManager.h"
#include "Vector2D.h"
#include "ECS/ECS.h"
#include <SDL2/SDL_ttf.h>

class AssetManager{

public:
	//Response for create textures and Game objects
	AssetManager(Manager * man);
	~AssetManager();

	//Game Objects
	void CreateProjectile(Vector2D pos, Vector2D vel, int range, int speed, std::string id);

	//Texture Management
	void AddTexture(std::string id, const char* path);
	SDL_Texture* GetTexture(std::string id);

	void AddFont(std::string id, std::string path, int fontSize);
	TTF_Font* GetFont(std::string id);

private:
	Manager * manager;

	//Sign a Key for Value -> ID 
	std::map<std::string, SDL_Texture*> textures;
	std::map<std::string, TTF_Font*> fonts;

};