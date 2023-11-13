#pragma once

#include <string>

class AABBCollider;
class CircleCollider;

class Shape;

class Collider
{
public:
	float _posX;
	float _posY;
	float _sizeX;
	float _sizeY;
	float _radius;

public:
	Collider(float posX, float posY, float sizeX, float sizeY);
	Collider(float posX, float posY, float radius);

	bool colliding(Collider* o_OtherCollider);
	std::string collidingSide(Collider* o_OtherCollider);

	virtual bool isColliding(const AABBCollider& o_AABBCollider) = 0;
	virtual bool isColliding(const CircleCollider & o_circleCollider) = 0;

	virtual std::string checkCollidingSide(const AABBCollider& o_AABBCollider) = 0;
	virtual std::string checkCollidingSide(const CircleCollider& o_circleCollider) = 0;
};
