#pragma once
#include "Collider.h"

class AABB_Collider : public Collider
{
public:
	AABB_Collider(float posX, float posY, float sizeX, float sizeY, sf::RectangleShape* o_graphic);

	bool isColliding(const sf::RectangleShape& o_shape, float posX, float posY, float sizeX, float sizeY) override;
	bool isColliding(const sf::CircleShape& o_shape, float posX, float posY, float radius) override;

	std::string checkCollidingSide(const sf::RectangleShape& o_shape, float posX, float posY, float sizeX, float sizeY) override;
	std::string checkCollidingSide(const sf::CircleShape& o_shape, float posX, float posY, float radius) override;
};