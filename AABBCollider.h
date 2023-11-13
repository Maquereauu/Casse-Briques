#pragma once

#include "Collider.h"

#include <string>

class CircleCollider;

class AABBCollider : public Collider
{
public:
	AABBCollider(float posX, float posY, float sizeX, float sizeY);

	bool isColliding(const AABBCollider& o_AABBCollider) override;
	bool isColliding(const CircleCollider& o_circleCollider) override;

	std::string checkCollidingSide(const AABBCollider& o_AABBCollider) override;
	std::string checkCollidingSide(const CircleCollider& o_circleCollider) override;
};