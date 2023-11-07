#pragma once
#include <vector>

namespace Math
{
	class Vector2
	{
	private:
		float _x; 
		float _y;

	public:
		Vector2(float x, float y);

		float getX();
		float getY();
		void setX(float x);
		void setY(float y);
		void setAll(float x, float y);
	};

	std::vector<float> normalizeVector(std::vector<float> vector);
};

