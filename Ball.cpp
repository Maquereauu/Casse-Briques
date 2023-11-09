#include "Ball.h"

Ball::Ball(float radius, float x,float y,float speed) : GameObject(radius, x, y, speed)
{
	setVector(0.f, 0.f);
}