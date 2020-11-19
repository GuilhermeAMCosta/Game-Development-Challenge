#pragma once
#include "Components.h"
#include "../Vector2D.h"

class TransformComponent : public Component{
public:
	Vector2D position;
	Vector2D velocity;

	int height = 64;
	int widht = 64;
	int scale = 1;
	int speed = 2;

	//Default
	TransformComponent(){
		position.Zero();
	}

	TransformComponent(int sc){
		position.x = 400;
		position.y = 320;
		scale = sc;
	}

	//To Manage only with Points
	TransformComponent(float x, float y){
		position.x = x;
		position.y = y;
	}
	//To Manage with Points and Distance
	TransformComponent(float x, float y, int w, int h, int sc){
		position.x = x;
		position.y = y;
		height = h;
		widht = w;
		scale = sc;
	}

	void init() override{
		velocity.Zero();
	}

	void update() override{
		position.x += static_cast<int>(velocity.x * speed);
		position.y += static_cast<int>(velocity.y * speed);
		
		//Pkayer Position
		// position.x += velocity.x * speed;
		// position.y += velocity.y * speed;
	}
};