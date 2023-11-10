#pragma once
#include "GameObject.h"

class Brick :public GameObject
{
private:
	std::map<int, sf::Color> _colors;
	int _hp;

public:
	Brick(float sizeX, float sizeY, float posX, float posY, float speed, int hp);
	void setColor();
	int getHp();
	bool isDisplayBrick();
	void displayBrick(sf::RenderWindow* o_window);
	//void displayBricks(sf::RenderWindow* o_window, std::vector<Brick*> listBricks);

};