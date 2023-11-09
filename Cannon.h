#pragma once
#include "GameObject.h"
class Cannon : public GameObject
{
public:
	Cannon(float sizeX, float sizeY, float posX, float posY, float speed);
	void cannonMove(Math::Vector2 mouseVector, float* oldAngle, float* angle);
	void cannonFire(Math::Vector2 mouseVector);
};

