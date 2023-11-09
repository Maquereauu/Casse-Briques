#pragma once
#include "GameObject.h"
class Cannon : public GameObject
{
private:
	float _oldAngle;
	float _angle;
public:
	Cannon(float sizeX, float sizeY, float posX, float posY, float speed);
	void cannonMove(Math::Vector2 mouseVector);
	void cannonFire(Math::Vector2 mouseVector);
};

