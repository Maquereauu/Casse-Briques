#pragma once
#include "GameObject.h"
class Ball : public GameObject
{
public:
	Ball(float x,float y,Math::Vector2 vector,float speed,float radius);
};

