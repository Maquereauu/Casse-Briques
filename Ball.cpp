#include "Ball.h"

Ball::Ball(float x,float y,Math::Vector2* vector,float speed,float radius) : GameObject(radius, x, y, speed) 
{
	setVector(vector.x,vector.y);
}