#include "Ball.h"

Ball::Ball(float x,float y,float speed,float radius) : GameObject(radius, x, y, speed) 
{
	setVector(0.f,0.f);
}