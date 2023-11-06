#include "GameObject.h"

GameObject::GameObject(float sizeX, float sizeY, float posX, float posY)
{
	_sizeX = sizeX;
	_sizeY = sizeY;
	_posX = posX;
	_posY = posY;
	
	int* i = new int(5);

	sf::RectangleShape* rectangle = new sf::RectangleShape(sf::Vector2f(_sizeX, _sizeY));
	rectangle->setFillColor(sf::Color::Blue);
	rectangle->setPosition(_posX, _posY);
	
	_graphic = rectangle;
}

GameObject::GameObject(float radius, float posX, float posY)
{
	_radius = radius;
	_posX = posX;
	_posY = posY;

	sf::CircleShape* circle = new sf::CircleShape(_radius);
	circle->setFillColor(sf::Color::Red);
	circle->setPosition(_posX, _posY);

	_graphic = circle;
}

sf::Shape& GameObject::getShape() 
{
	return *_graphic;
}