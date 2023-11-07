#include "GameObject.h"

GameObject::GameObject(float sizeX, float sizeY, float posX, float posY, float speed)
{
	_sizeX = sizeX;
	_sizeY = sizeY;
	_posX = posX;
	_posY = posY;
	_speed = speed;
	
	sf::RectangleShape* rectangle = new sf::RectangleShape(sf::Vector2f(_sizeX, _sizeY));
	rectangle->setFillColor(sf::Color::Blue);
	rectangle->setPosition(_posX, _posY);
	
	_graphic = rectangle;

	sf::Vector2f v;
	v.x;
	v.y;

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

GameObject::GameObject() : GameObject(100.f, 100.f, 100.f, 100.f, 90.f) 
{

}

sf::Shape& GameObject::getShape() 
{
	return *_graphic;
}


bool GameObject::isColliding(GameObject object)
{
	bool collidesX = (_posX + _sizeX >= object._posX) && (object._posX + object._sizeX >= _posX);

	bool collidesY = (_posY + _sizeY >= object._posY) && (object._posY + object._sizeY >= _posY);

	if (collidesX && collidesY)
	{
		return true;
	}
	return false;
}

GameObject GameObject::collide(std::vector<GameObject> list)
{
	for (int i = 0; i < list.size(); i++) {
		if (isColliding(list[i])) {
			return list[i];
		}
	}
	return GameObject();
}

void GameObject::moveShape(float deltaTime, Math::Vector2 direction)
{
	_posX = _posX + (direction.x * deltaTime) * _speed;
	_posY = _posY + (direction.y * deltaTime) * _speed;
	
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
	_graphic->setOrigin(_sizeX / 2.f,  (3 *_sizeY) / 4);
}