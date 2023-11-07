#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>


namespace Math
{
	class Vector2 : public sf::Vector2f
	{
	public:
		float& _x;
		float& _y;

		Vector2(float x, float y);

		void setAll(float x, float y);
		Math::Vector2 getNormalizeVector();
		void normalizeVector();
		bool compareVector(Math::Vector2& vectorResult);
		float scalarProduct(Math::Vector2& vector);
		float getAngle(Math::Vector2& vector);
	};
};

