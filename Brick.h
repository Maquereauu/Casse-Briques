#pragma once
#include "GameObject.h"

class RenderWindow;

class Brick :public GameObject
{
private:
	std::map<int, sf::Color> _colors;
	int _hp;
	int _maxHp;
public:
	Brick(float sizeX, float sizeY, float posX, float posY, float speed, int hp);

	int getHp();
	void setColor();
	void minusHp();
	void isDisplayBrick(); // verification if the brick have more than 0 hp
	void onCollisionEnter(GameObject* object) override;
	void heal();
};