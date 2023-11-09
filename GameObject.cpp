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

sf::Shape& GameObject::getShape()
{
	return *_graphic;
}


bool GameObject::isColliding(const GameObject& object)
{
	bool collidesX = (_posX + _sizeX >= object._posX) && (object._posX + object._sizeX >= _posX);

	bool collidesY = (_posY + _sizeY >= object._posY) && (object._posY + object._sizeY >= _posY);

	if (collidesX && collidesY)
	{
		return true;
	}
	return false;
}

bool GameObject::ballIsColliding(const GameObject& object)
{
	bool collidesX = (_posX + _radius*1.5 >= object._posX) && (object._posX + object._sizeX >= _posX - _radius/2);

	bool collidesY = (_posY + _radius*1.5 >= object._posY) && (object._posY + object._sizeY >= _posY - _radius/2);

	if (collidesX && collidesY)
	{
		return true;
	}
	return false;
}

void GameObject::collide(const std::vector<GameObject*>& list)
{
	for (int i = 0; i < list.size(); i++) {
		if (ballIsColliding(*list[i])) {
			if (_collidingWith.size() != 0)
			{
				for (int j = 0; j < _collidingWith.size(); j++)
				{
					if (_collidingWith[j] == list[i])
					{
						onCollisionStay();
					}
					else {
						onCollisionEnter(list[i]);
					}
				}
			}
			else {
			onCollisionEnter(list[i]);
			}
		}
		else {
			if (_collidingWith.size() != 0)
			{
				for (int j = 0; j < _collidingWith.size(); j++)
				{
					if (_collidingWith[j] == list[i])
					{
						onCollisionExit(list[i]);
					}
				}
			}
		}
	}
}

std::string GameObject::checkCollidingSide(const GameObject& object)
{
	/* Renvoie le coté sur lequel on collide à partir des dimensions du vecteur entre les deux centres des GameObjects */
	Math::Vector2 centerToCenter(object._posX + object._sizeX/2 - _posX + _sizeX / 2, object._posY + object._sizeY / 2 - _posY + _sizeY / 2);
	if (std::abs(centerToCenter.x) > std::abs(centerToCenter.y)) {
		return (centerToCenter.x > 0) ? "left" : "right";
	}
		return (centerToCenter.y > 0) ? "top" : "bottom";
}


std::string GameObject::ballCheckCollidingSide(const GameObject& object)
{
	/* Renvoie le coté sur lequel on collide à partir des dimensions du vecteur entre les deux centres des GameObjects */
	Math::Vector2 centerToCenter(object._posX + object._sizeX / 2 - _posX , object._posY + object._sizeY / 2 - _posY);
	std::cout << object._posX << "/" << _posX << "/" << _radius << std::endl;
	std::cout << std::abs(centerToCenter.x) << "/" << std::abs(centerToCenter.y) << std::endl;
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

void GameObject::setOriginPointCircle()
{
	_graphic->setOrigin(_radius / 2, _radius / 2);
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

const Math::Vector2 GameObject::getVect()
{
	return _vector;
}

void GameObject::onCollisionEnter(GameObject* object) 
{
	_collidingWith.push_back(object);
	std::cout << ballCheckCollidingSide(*object) << std::endl;
	bounce(ballCheckCollidingSide(*object));
}

void GameObject::onCollisionStay()
{
	//B)
}

void GameObject::onCollisionExit(GameObject* object)
{
	_collidingWith.erase(std::remove(_collidingWith.begin(), _collidingWith.end(), object), _collidingWith.end());
}

void GameObject::setPos(float x, float y) {
	_posX = x - _radius / 2;
	_posY = y;
}

