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

GameObject::GameObject() : GameObject(100.f, 100.f, 1300.f, 300.f, 90.f)
{

}

sf::Shape& GameObject::getShape()
{
	return *_graphic;
}


bool GameObject::isColliding(const GameObject& object)
{
	//int i = 0;

	//int* pi = &i;
	//*pi = 5;

	//int& ri = i;
	//ri = 5;


	bool collidesX = (_posX + _sizeX >= object._posX) && (object._posX + object._sizeX >= _posX);

	bool collidesY = (_posY + _sizeY >= object._posY) && (object._posY + object._sizeY >= _posY);

	if (collidesX && collidesY)
	{
		return true;
	}
	return false;
}



void GameObject::collide(const std::vector<GameObject*>& list)
{
	for (int i = 0; i < list.size(); i++) {
		if (isColliding(*list[i])) {
			std::cout << checkCollidingSide(*list[i]) << std::endl;
			bounce(checkCollidingSide(*list[i]));
		}
	}
}

std::string GameObject::checkCollidingSide(const GameObject& object)
{
	/* Renvoie le coté sur lequel on collide à partir des dimensions du vecteur entre les deux centres des GameObjects */
	Math::Vector2 centerToCenter(object._posX - _posX, object._posY - _posY);
	if (std::abs(centerToCenter.x) > std::abs(centerToCenter.y)) {
		return (centerToCenter.x > 0) ? "left" : "right";
	}
		return (centerToCenter.y > 0) ? "top" : "bottom";
}

void GameObject::bounce(std::string side) 
{
	int i = _sides[side];
	switch(i)
	{
	case 1: // left
		_vector.x *= -1;
		break;
	case 2: // top
		_vector.y *= -1;
		break;
	case 3: // right
		_vector.x *= -1;
		break;
	case 4: // bottom
		_vector.y *= -1;
		break;
	}

}

void GameObject::moveShape(float deltaTime,const Math::Vector2& direction)
{
	_posX = _posX + (direction.x * deltaTime) * _speed;
	_posY = _posY + (direction.y * deltaTime) * _speed;

	_graphic->setPosition(_posX, _posY);
}

void GameObject::rotateShape(float rotateDegree)
{
	_rotate += rotateDegree;
	_graphic->setRotation(_rotate);
}

void GameObject::setOriginPoint()
{
	_graphic->setOrigin(_sizeX / 2.f, _sizeY / 2.f);
}

void GameObject::setOriginPointOnBase()
{
	_graphic->setOrigin(_sizeX / 2.f, (3 * _sizeY) / 4);
}
Math::Vector2 GameObject::getPos()
{
	return Math::Vector2::Vector2(_posX, _posY);
}

void GameObject::setVector(float x, float y)
{
	_vector.x = x;
	_vector.y = y;
}

const Math::Vector2& GameObject::getVect()
{
	return _vector;
}
