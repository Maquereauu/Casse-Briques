#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class GameObject
{
private :
	float _sizeX;
	float _sizeY;
	float _posX;
	float _posY;
	float _radius;
	std::string _geometry;
	sf::Shape* _graphic;

public:
	GameObject(float sizeX, float sizeY, float posX, float posY);
	GameObject(float radius, float posX, float posY);
	sf::Shape& getShape();
};

