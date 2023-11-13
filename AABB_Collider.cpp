#include "AABB_Collider.h"

AABB_Collider::AABB_Collider(float posX, float posY, float sizeX, float sizeY, sf::RectangleShape* o_graphic) : Collider(posX, posY, sizeX, sizeY, o_graphic) {};

bool AABB_Collider::isColliding(const sf::RectangleShape& o_shape, float posX, float posY, float sizeX, float sizeY)
{
	bool collidesX = (_posX + _sizeX >= posX) && (posX + sizeX >= _posX);

	bool collidesY = (_posY + _sizeY >= posY) && (posY + sizeY >= _posY);

	if (collidesX && collidesY)
	{
		return true;
	}
	return false;
}

bool AABB_Collider::isColliding(const sf::CircleShape& o_shape, float posX, float posY, float radius)
{
	bool collidesX = (posX + radius >= _posX) && (_posX + _sizeX >= posX - radius);

	bool collidesY = (posY + radius >= _posY) && (_posY + _sizeY >= posY - radius);

	if (collidesX && collidesY)
	{
		return true;
	}
	return false;
}

std::string AABB_Collider::checkCollidingSide(const sf::RectangleShape& o_shape, float posX, float posY, float sizeX, float sizeY)
{
	/* Renvoie le coté sur lequel on collide à partir des dimensions du vecteur entre les deux centres des GameObjects */
	Math::Vector2 centerToCenter((posX + (sizeX / 2)) - (_posX + (_sizeX / 2)), (posY + (sizeY / 2)) - (_posY + (_sizeY / 2)));
	if (std::abs(centerToCenter.x) > std::abs(centerToCenter.y)) {
		return (centerToCenter.x > 0) ? "left" : "right";
	}
	return (centerToCenter.y > 0) ? "top" : "bottom";
}

std::string AABB_Collider::checkCollidingSide(const sf::CircleShape& o_shape, float posX, float posY, float radius)
{
	/* Renvoie le coté sur lequel on collide à partir des dimensions du vecteur entre les deux centres des GameObjects */
	Math::Vector2 centerToCenter(((_posX + (_sizeX / 2)) - posX), ((_posY + (_sizeY / 2)) - posY));
	std::cout << (_posY + _sizeY / 2) << "/" << posY << "/" << radius << std::endl;
	std::cout << std::abs(centerToCenter.x) << "/" << std::abs(centerToCenter.y) << std::endl;
	if (std::abs(centerToCenter.x) > std::abs(centerToCenter.y)) {
		return (centerToCenter.x > 0) ? "left" : "right";
	}
	return (centerToCenter.y > 0) ? "top" : "bottom";
}