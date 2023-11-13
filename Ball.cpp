#include "Ball.h"

Ball::Ball(float radius, float x,float y,float speed) : GameObject(radius, x, y, speed)
{
	setOriginPointCircle();
	setVector(0.f, 0.f);
}

Ball::Ball() : Ball(20.f, 500.f, 500.f, 180.f) {};