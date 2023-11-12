#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "GameObject.h"

class Collider : public GameObject
{
public:
	Collider(float sizeX, float sizeY, float posX, float posY, float speed);

	virtual bool isColliding(const GameObject& object);
	virtual std::string checkCollidingSide(const GameObject& object);

	virtual bool ballIsColliding(const GameObject& object);
	virtual std::string ballCheckCollidingSide(const GameObject& object);

	virtual void collide(const std::vector<GameObject*>& list);
	virtual void ballCollide(const std::vector<GameObject*>& list);
};

