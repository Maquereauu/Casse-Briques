#pragma once
#include "GameObject.h"

class Ball;

class Cannon : public GameObject
{
private:
	float _oldAngle;
	float _angle;

public:
	Cannon(float sizeX, float sizeY, float posX, float posY, float speed);
	Cannon();

	void move(Math::Vector2 mouseVector);
	void fire(Math::Vector2 mouseVector, Ball* o_ball);
};

