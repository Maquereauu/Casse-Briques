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
		static Vector2 upVector;
		static Vector2 downVector;
		static Vector2 leftVector;
		static Vector2 rightVector;

		float& _x;
		float& _y;

		Vector2(float x, float y);

		void setAll(float x, float y);
		Math::Vector2 getNormalizeVector();
		void normalizeVector();
		bool compareVector(Math::Vector2& vectorResult);
		float scalarProduct(Math::Vector2& vector);
		float getAngle(Math::Vector2 vector);
		void reBound(Math::Vector2* ballVector);
		static Math::Vector2 createVector(Math::Vector2 vector, float x1, float y1);
	};
};

