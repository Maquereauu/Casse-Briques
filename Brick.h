#pragma once
#include "GameObject.h"

class RenderWindow;

class Brick :public GameObject
{
private:
	std::map<int, sf::Color> _colors;
	int _hp;

public:
	Brick(float sizeX, float sizeY, float posX, float posY, float speed, int hp);
	void setColor();
	int getHp();
	void minusHp();
	void isDisplayBrick();
	void onCollisionEnter(GameObject* object) override;
};