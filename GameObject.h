#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <iostream>
#include "Math.h"
class GameObject
{
public:
	std::map<std::string, int> _sides = {{"left",1},{"top",2},{"right",3},{"bottom",4}};
private :
	float _sizeX;
	float _sizeY;
	float _posX;
	float _posY;
	float _radius;
	float _speed;
	float _rotate;
	std::string _geometry;
	sf::Shape* _graphic;
	Math::Vector2 _vector;
	float deltaTime;
	std::vector<GameObject*> _collidingWith;

public:
	GameObject(float sizeX, float sizeY, float posX, float posY, float speed);
	GameObject(float radius, float posX, float posY, float speed);

	sf::Shape& getShape();
	void moveShape(float deltaTime, const Math::Vector2& direction);
	void rotateShape(float rotateDegree);
	void setOriginPoint();
	void setOriginPointOnBase();
	bool isColliding(const GameObject& object);
	void collide(const std::vector<GameObject*>& list);
	std::string checkCollidingSide(const GameObject& object);
	void bounce(std::string side);
	Math::Vector2 getPos();
	void setVector(float x, float y);
	const Math::Vector2 getVect();

	virtual void onCollisionEnter(GameObject* object);  // virtual permet l'override pour les enfants de la classe
	virtual void onCollisionStay();
	virtual void onCollisionExit(GameObject* object);
};

