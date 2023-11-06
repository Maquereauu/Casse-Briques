#include "Math.h"

std::vector<float> Math::normalizeVector(std::vector<float> vector)
{
	float normal = pow(vector[0], 2) + pow(vector[1], 2);
	normal = pow(normal, 1 / 2.f);
	return { vector[0] / normal, vector[1] / normal };
}