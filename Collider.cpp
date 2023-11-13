#include "Collider.h"


Collider::Collider(float posX, float posY, float sizeX, float sizeY, sf::RectangleShape* o_rectangle)
{
	_posX = posX;
	_posY = posY;
	_sizeX = sizeX;
	_sizeY = sizeY;
	_graphic = o_rectangle;
}

Collider::Collider(float posX, float posY, float radius, sf::CircleShape* o_circle)
{
	_radius = radius;
	posX = posX;
	posY = posY;
	_graphic = o_circle;
}

bool Collider::isColliding(const sf::RectangleShape& o_shape, float posX, float posY, float sizeX, float sizeY)
{

}

bool Collider::isColliding(const sf::CircleShape& o_shape, float posX, float posY, float radius)
{

}

std::string Collider::checkCollidingSide(const sf::RectangleShape& o_shape, float posX, float posY, float sizeX, float sizeY)
{

}

std::string Collider::checkCollidingSide(const sf::CircleShape& o_shape, float posX, float posY, float radius)
{

}


