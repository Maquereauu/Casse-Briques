#pragma once
#include "GameObject.h"

class Ball : public GameObject
{
public:
	std::string _side;
	Ball();
	Ball(float radius, float x,float y,float speed);
	float getRadius();
	void onCollisionEnter(GameObject* object) override;
};