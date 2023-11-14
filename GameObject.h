#pragma once

#include <string>
#include <vector>
#include <map>

#include "Math.h"

class sf::Shape;
class Collider;

class GameObject
{
public:
	std::map<std::string, int> _sides = {{"left",1},{"top",2},{"right",3},{"bottom",4}};
protected :
	float _sizeX;
	float _sizeY;
	float _posX;
	float _posY;
	float _speed;
	float _rotate;
	std::string _geometry;
	sf::Shape* _graphic;
	Collider* _collider;
	float deltaTime;
	std::vector<GameObject*> _collidingWith;

protected:
	Math::Vector2 _vector;

public:
	GameObject(float sizeX, float sizeY, float posX, float posY, float speed); // rectangle
	GameObject(float radius, float posX, float posY, float speed); // ball
	sf::Shape& getShape();
	void moveShape(float deltaTime, const Math::Vector2& direction);
	void rotateShape(float rotateDegree);
	void setOrigin(float fRatioxX, float fRatioY);
	void setOriginCenter();
	void setOriginPointOnBase();

	bool isColliding(const GameObject& object);
	void collide(const std::vector<GameObject*>& list);
	std::string checkCollidingSide(const GameObject& object);
	std::string ballCheckCollidingSide(const GameObject& object);

	void bounce(std::string side);
	Math::Vector2 getPos();
	void setPos(float x, float y);
	void setVector(float x, float y);
	const Math::Vector2 getVect();


	virtual void launchCollisionEnter(GameObject* object);  // virtual permet l'override pour les enfants de la classe
	virtual void launchCollisionStay();
	virtual void launchCollisionExit(GameObject* object);

	virtual void onCollisionEnter(GameObject* object);  // virtual permet l'override pour les enfants de la classe
	virtual void onCollisionStay();
	virtual void onCollisionExit(GameObject* object);
};

