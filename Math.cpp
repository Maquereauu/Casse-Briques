#include "Math.h"

Math::Vector2 Math::normalizeVector(Math::Vector2 vector)
{
	float normal = pow(vector.getX(), 2) + pow(vector.getY(), 2);
	normal = pow(normal, 1 / 2.f);
	Math::Vector2 normalVector = Math::Vector2(vector.getX() / normal, vector.getY() / normal);

	return normalVector;
}

Math::Vector2 Math::unitaryVector(Math::Vector2 vector)
{
	Math::Vector2 normalVector = Math::normalizeVector(vector);
	Math::Vector2 unitaryVector = Math::Vector2(vector.getX() / normalVector.getX(), vector.getY() / normalVector.getY());

	return unitaryVector;
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

Math::Vector2 Math::calculVectorFromCoordinates(float startX, float startY, float finishX, float finishY)
{
	Math::Vector2 vector = Math::Vector2(finishX - startX, finishY - startY);

	Math::Vector2 unitaryVector = Math::unitaryVector(vector);

	return unitaryVector;
}

std::vector<float> Math::transformVector2ToVector(Math::Vector2 vector)
{
	return { vector.getX(), vector.getY() };
}