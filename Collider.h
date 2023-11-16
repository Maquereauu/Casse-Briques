#pragma once

#include <string>

class AABBCollider;
class CircleCollider;

class Shape;

class Collider
{
private:
	typedef enum sides
	{
		left,
		top,
		right,
		bottom
	};
public:
	float& _posX;
	float& _posY;

	Collider(float& posX, float& posY);

	bool colliding(Collider* o_OtherCollider);
	std::string collidingSide(Collider* o_OtherCollider);

	virtual bool isColliding(const AABBCollider& o_AABBCollider) = 0;
	virtual bool isColliding(const CircleCollider & o_circleCollider) = 0;

	virtual std::string checkCollidingSide(const AABBCollider& o_AABBCollider) = 0;
	virtual std::string checkCollidingSide(const CircleCollider& o_circleCollider) = 0;
};
