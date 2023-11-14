#pragma once

#include "Collider.h"

#include <string>

class AABBCollider;

class CircleCollider : public Collider
{
public:
	float& _sizeX;
	float& _sizeY;

	CircleCollider(float& posX, float& posY, float& _sizeX, float& _sizeY);

	bool isColliding(const AABBCollider& o_AABBCollider) override;
	bool isColliding(const CircleCollider& o_circleCollider) override;

	std::string checkCollidingSide(const AABBCollider& o_AABBCollider) override;
	std::string checkCollidingSide(const CircleCollider& o_circleCollider) override;
};