#include "GameObject.h"
#include <vector>

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


bool GameObject::isColliding(GameObject object) 
{
	if (_sizeX > object._sizeX) {
		if (object._posX >= _posX && object._posX <= _posX + _sizeX)
		{
			if (_sizeY > object._sizeY) {
				if (object._posY >= _posY && object._posY <= _posY + _sizeY) {
					return true;
				}
			}
			else {
				if (object._posY + object._sizeY >= _posY && object._posY + object._sizeY <= _posY) {
					return true;
				}
			}
		}
	}
	else {
		if (object._posX + object._sizeX >= _posX && object._posX + object._sizeX <= _posX)
		{
			return true;
		}
	}
	if (_sizeY > object._sizeY) {

	}
	else {

	}
	return false;
}

GameObject GameObject::collide(std::vector<GameObject> list)
{
	for (int i = 0; i < list.size(); i++) {
		isColliding(list[i]);
	}
}
