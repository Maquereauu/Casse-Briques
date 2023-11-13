#pragma once
#include "Collider.h"
class CircleCollider : public Collider
{
	CircleCollider(float posX, float posY, float radius, sf::CircleShape* o_graphic);

	bool isColliding(const sf::RectangleShape& o_shape, float posX, float posY, float sizeX, float sizeY) override;
	bool isColliding(const sf::CircleShape& o_shape, float posX, float posY, float radius) override;

	std::string checkCollidingSide(const sf::RectangleShape& o_shape, float posX, float posY, float sizeX, float sizeY) override;
};