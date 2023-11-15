#include "Ball.h"

#include "GameObjectEnum.h"
Ball::Ball(float radius, float x,float y,float speed) : GameObject(radius, x, y, speed, GoLabel::ball)
{
	//setOriginCenter();
	setVector(0.f, 0.f);
}

Ball::Ball() : Ball(20.f, 700.f, 500.f, 180.f) {};

float Ball::getRadius() {
	return _sizeX / 2;
}