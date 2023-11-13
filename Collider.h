#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "GameObject.h"

class Collider
{
public:
	float _posX;
	float _posY;
	float _sizeX;
	float _sizeY;
	float _radius;
	sf::Shape* _graphic;

public:
	Collider(float posX, float posY, float sizeX, float sizeY, sf::RectangleShape* o_rectangle);
	Collider(float posX, float posY, float radius, sf::CircleShape* o_circle);

	virtual bool isColliding(const sf::RectangleShape& o_shape, float posX, float posY, float sizeX, float sizeY);
	virtual bool isColliding(const sf::CircleShape& o_shape, float posX, float posY, float radius);

	virtual std::string checkCollidingSide(const sf::RectangleShape& o_shape, float posX, float posY, float sizeX, float sizeY);
	virtual std::string checkCollidingSide(const sf::CircleShape& o_shape, float posX, float posY, float radius);
};
