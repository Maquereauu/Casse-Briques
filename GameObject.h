#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <iostream>
#include "Math.h"

class GameObject
{
private :
	float _sizeX;
	float _sizeY;
	float _posX;
	float _posY;
	float _radius;
	float _speed;
	float _rotate;
	std::string _geometry;
	sf::Shape* _graphic;

	std::vector<float> direction;
	float deltaTime;

public:
	GameObject(float sizeX, float sizeY, float posX, float posY, float speed);
	GameObject(float radius, float posX, float posY, float speed);
	GameObject();
	sf::Shape& getShape();
	void moveShape(float deltaTime, Math::Vector2 direction);
	void rotateShape(float rotateDegree);
	void setOriginPoint();
	void setOriginPointOnBase();
	bool isColliding(const GameObject& object);
	GameObject* collide(const std::vector<GameObject*>& list);
	Math::Vector2 getPos();
};

