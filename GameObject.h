#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

class GameObject
{
private :
	float _sizeX;
	float _sizeY;
	float _posX;
	float _posY;
	float _radius;
	float _speed;
	std::string _geometry;
	sf::Shape* _graphic;

	std::vector<float> direction;
	float deltaTime;

public:
	GameObject(float sizeX, float sizeY, float posX, float posY, float speed);
	GameObject(float radius, float posX, float posY, float speed);
	sf::Shape& getShape();
	void moveShape(float deltaTime, std::vector<float> direction);
};

