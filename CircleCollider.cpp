#include "CircleCollider.h"

#include "AABBCollider.h"
#include "Math.h"

CircleCollider::CircleCollider(float posX, float posY, float radius) : Collider(posX, posY, radius) {};

bool CircleCollider::isColliding(const AABBCollider& o_AABBCollider)
{
	bool collidesX = (_posX + _radius >= o_AABBCollider._posX) && (o_AABBCollider._posX + o_AABBCollider._sizeX >= _posX - _radius);

	bool collidesY = (_posY + _radius >= o_AABBCollider._posY) && (o_AABBCollider._posY + o_AABBCollider._sizeY >= _posY - _radius);

	if (collidesX && collidesY)
	{
		return true;
	}
	return false;
}

bool CircleCollider::isColliding(const CircleCollider& o_circleCollider)
{
	bool collidesX = (o_circleCollider._posX + o_circleCollider._radius >= _posX) && (_posX + _radius >= o_circleCollider._posX - o_circleCollider._radius);

	bool collidesY = (o_circleCollider._posY + o_circleCollider._radius >= _posY) && (_posY + _radius >= o_circleCollider._posY - o_circleCollider._radius);

	if (collidesX && collidesY)
	{
		return true;
	}
	return false;
}

std::string CircleCollider::checkCollidingSide(const AABBCollider& o_AABBCollider)
{
	Math::Vector2 centerToCenter(((o_AABBCollider._posX + (o_AABBCollider._sizeX / 2)) - _posX), ((o_AABBCollider._posY + (o_AABBCollider._sizeY / 2)) - _posY));
	std::cout << (o_AABBCollider._posY + o_AABBCollider._sizeY / 2) << "/" << _posY << "/" << _radius << std::endl;
	std::cout << std::abs(centerToCenter.x) << "/" << std::abs(centerToCenter.y) << std::endl;
	if (std::abs(centerToCenter.x) > std::abs(centerToCenter.y)) {
		return (centerToCenter.x > 0) ? "left" : "right";
	}
	return (centerToCenter.y > 0) ? "top" : "bottom";
}

std::string CircleCollider::checkCollidingSide(const CircleCollider& o_circleCollider)
{
	return "pas fait";
}
