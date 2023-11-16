#include "Ball.h"

#include "GameObjectEnum.h"
Ball::Ball(float radius, float x,float y,float speed) : GameObject(radius, x, y, speed, -1)
{
	//setOriginCenter();
	setVector(0.f, 0.f);
}

Ball::Ball() : Ball(15.f, 700.f, 500.f, 180.f) {};

float Ball::getRadius() {
	return _sizeX / 2;
}

void Ball::onCollisionEnter(GameObject* object) {
	std::string collidingSide = checkCollidingSide(*object);
	if(collidingSide != _side)
	{
		bounce(collidingSide);
	}
	_side = collidingSide;
}