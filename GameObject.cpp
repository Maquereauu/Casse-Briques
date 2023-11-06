#include "GameObject.h"

GameObject::GameObject(float sizeX, float sizeY, float posX, float posY, float speed)
{
	_sizeX = sizeX;
	_sizeY = sizeY;
	_posX = posX;
	_posY = posY;
	_speed = speed;
	
	int* i = new int(5);

	sf::RectangleShape* rectangle = new sf::RectangleShape(sf::Vector2f(_sizeX, _sizeY));
	rectangle->setFillColor(sf::Color::Blue);
	rectangle->setPosition(_posX, _posY);
	
	_graphic = rectangle;
}

GameObject::GameObject(float radius, float posX, float posY, float speed)
{
	_radius = radius;
	_posX = posX;
	_posY = posY;
	_speed = speed;

	sf::CircleShape* circle = new sf::CircleShape(_radius);
	circle->setFillColor(sf::Color::Red);
	circle->setPosition(_posX, _posY);

	_graphic = circle;
}

sf::Shape& GameObject::getShape() 
{
	return *_graphic;
}

void GameObject::moveShape(float deltaTime, std::vector<float> direction)
{
	_posX = _posX + ( direction[0] * deltaTime) * _speed;
	_posY = _posY + (direction[1] * deltaTime) * _speed;
	_graphic->setPosition(_posX, _posY);
}

void GameObject::rotateShape(float deltaTime, float rotateDegree)
{
	_rotate += (rotateDegree * deltaTime);
	_graphic->setRotation(_rotate);
}

void GameObject::setOriginPoint()
{
	_graphic->setOrigin(_sizeX / 2.f , _sizeY / 2.f);
}

void GameObject::setOriginPointOnBase()
{
	_graphic->setOrigin(_sizeX / 2.f, _sizeY);
}