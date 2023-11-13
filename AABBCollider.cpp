#include "AABBCollider.h"

#include "CircleCollider.h"
#include "Math.h"

AABBCollider::AABBCollider(float posX, float posY, float sizeX, float sizeY) : Collider(posX, posY, sizeX, sizeY) {};

bool AABBCollider::isColliding(const AABBCollider& o_AABBCollider)
{
	bool collidesX = (_posX + _sizeX >= o_AABBCollider._posX) && (o_AABBCollider._posX + o_AABBCollider._sizeX >= _posX);

	bool collidesY = (_posY + _sizeY >= o_AABBCollider._posY) && (o_AABBCollider._posY + o_AABBCollider._sizeY >= _posY);

	if (collidesX && collidesY)
	{
		return true;
	}
	return false;
}

bool AABBCollider::isColliding(const CircleCollider& o_circleCollider)
{
	bool collidesX = (o_circleCollider._posX + o_circleCollider._radius >= _posX) && (_posX + _radius >= o_circleCollider._posX - o_circleCollider._radius);

	bool collidesY = (o_circleCollider._posY + o_circleCollider._radius >= _posY) && (_posY + _radius >= o_circleCollider._posY - o_circleCollider._radius);

	if (collidesX && collidesY)
	{
		return true;
	}
	return false;
}

std::string AABBCollider::checkCollidingSide(const AABBCollider& o_AABBCollider)
{
	/* Renvoie le coté sur lequel on collide à partir des dimensions du vecteur entre les deux centres des GameObjects */
	Math::Vector2 centerToCenter((o_AABBCollider._posX + (o_AABBCollider._sizeX / 2)) - (_posX + (_sizeX / 2)), (o_AABBCollider._posY + (o_AABBCollider._sizeY / 2)) - (_posY + (_sizeY / 2)));
	if (std::abs(centerToCenter.x) > std::abs(centerToCenter.y)) {
		return (centerToCenter.x > 0) ? "left" : "right";
	}
	return (centerToCenter.y > 0) ? "top" : "bottom";
}

std::string AABBCollider::checkCollidingSide(const CircleCollider& o_circleCollider)
{
	/* Renvoie le coté sur lequel on collide à partir des dimensions du vecteur entre les deux centres des GameObjects */
	Math::Vector2 centerToCenter(((_posX + (_sizeX / 2)) - o_circleCollider._posX), ((_posY + (_sizeY / 2)) - o_circleCollider._posY));
	std::cout << (_posY + _sizeY / 2) << "/" << o_circleCollider._posY << "/" << o_circleCollider._radius << std::endl;
	std::cout << std::abs(centerToCenter.x) << "/" << std::abs(centerToCenter.y) << std::endl;
	if (std::abs(centerToCenter.x) > std::abs(centerToCenter.y)) {
		return (centerToCenter.x > 0) ? "left" : "right";
	}
	return (centerToCenter.y > 0) ? "top" : "bottom";
}