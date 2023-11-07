#include "Math.h"

std::vector<float> Math::normalizeVector(std::vector<float> vector)
{
	float normal = pow(vector[0], 2) + pow(vector[1], 2);
	normal = pow(normal, 1 / 2.f);
	return { vector[0] / normal, vector[1] / normal };
}

Math::Vector2::Vector2(float x, float  y)
{
	_x = x;
	_y = y;
};

float Math::Vector2::getX()
{
	return _x;
}

float Math::Vector2::getY()
{
	return _y;
}

void Math::Vector2::setX(float x)
{
	_x = x;
}

void Math::Vector2::setY(float y)
{
	_y = y;
}

void Math::Vector2::setAll(float x, float y)
{
	_x = x;
	_y = y;
}