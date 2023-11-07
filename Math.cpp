#include "Math.h"

Math::Vector2 Math::Vector2::getNormalizeVector()
{
	float normal = pow(x, 2) + pow(y, 2);
	normal = pow(normal, 1 / 2.f);
	Math::Vector2 normalVector = Math::Vector2(x / normal, y / normal);

	return normalVector;
}


Math::Vector2::Vector2(float x, float  y) : sf::Vector2f( x, y ), _x(this->x), _y(this->y)
{
}

void Math::Vector2::setAll(float x, float y)
{
	_x = x;
	_y = y;
}

void Math::Vector2::normalizeVector()
{
	float normal = pow(_x, 2) + pow(_y, 2);
	normal = pow(normal, 1 / 2.f);

	_x = _x / normal;
	_y = _y / normal;
}

bool Math::Vector2::compareVector(Math::Vector2& vectorResult)
{
	if (_x == vectorResult._x && _y == vectorResult._y)
	{
		return true;
	}
	return false;
}