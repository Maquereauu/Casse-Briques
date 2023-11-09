#pragma once
#include "GameObject.h"
class Ball : public GameObject
{
private:
	Math::Vector2* _ballVector;
public:
	Ball(float x,float y,Math::Vector2 vector,float speed,float radius);
	Math::Vector2 getVect();
};

