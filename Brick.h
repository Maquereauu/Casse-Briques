#pragma once
#include "GameObject.h"
#include "FileReader.h"

class Brick :public GameObject
{
private:
	std::map<int, sf::Color> _colors;
	int _hp;

public:
	Brick(float sizeX, float sizeY, float posX, float posY, float speed);
	void setColor();
	int getHp();
	bool isDisplayBrick();
	void displayBrick(float startX, float startY, sf::RenderWindow* o_window);

	static void displayBrickFromTxt(float startX, float startY, float gap, sf::RenderWindow* o_window, FileReader* o_fileReader);
};