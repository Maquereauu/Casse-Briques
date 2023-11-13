#include "CircleCollider.h"

CircleCollider::CircleCollider(float posX, float posY, float radius, sf::CircleShape* o_graphic) : Collider(posX, posY, radius, o_graphic) {};

bool CircleCollider::isColliding(const sf::RectangleShape& o_shape, float posX, float posY, float sizeX, float sizeY)
{
	bool collidesX = (_posX + _radius >= posX) && (posX + sizeX >= _posX - _radius);

	bool collidesY = (_posY + _radius >= posY) && (posY + sizeY >= _posY - _radius);

	if (collidesX && collidesY)
	{
		return true;
	}
	return false;
}

bool CircleCollider::isColliding(const sf::CircleShape& o_shape, float posX, float posY, float radius)
{
	bool collidesX = (posX + radius >= _posX) && (_posX + _radius >= posX - radius);

	bool collidesY = (posY + radius >= _posY) && (_posY + _radius >= posY - radius);

	if (collidesX && collidesY)
	{
		return true;
	}
	return false;
}

std::string CircleCollider::checkCollidingSide(const sf::RectangleShape& o_shape, float posX, float posY, float sizeX, float sizeY)
{
	Math::Vector2 centerToCenter(((posX + (sizeX / 2)) - _posX), ((posY + (sizeY / 2)) - _posY));
	std::cout << (posY + sizeY / 2) << "/" << _posY << "/" << _radius << std::endl;
	std::cout << std::abs(centerToCenter.x) << "/" << std::abs(centerToCenter.y) << std::endl;
	if (std::abs(centerToCenter.x) > std::abs(centerToCenter.y)) {
		return (centerToCenter.x > 0) ? "left" : "right";
	}
	return (centerToCenter.y > 0) ? "top" : "bottom";
}
