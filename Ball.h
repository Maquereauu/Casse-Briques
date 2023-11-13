#pragma once
#include "GameObject.h"
class Ball : public GameObject
{
public:
	Ball();
	Ball(float radius, float x,float y,float speed);
};