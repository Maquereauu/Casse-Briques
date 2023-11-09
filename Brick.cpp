#include "Brick.h"

Brick::Brick(float sizeX, float sizeY, float posX, float posY, float speed) : GameObject(sizeX, sizeY, posX, posY, speed)
{
	_colors = { {1, sf::Color::Red}, {2, sf::Color::Yellow}, {3, sf::Color::Blue}, {4, sf::Color::Green}, {5, sf::Color::White} };
	_hp = 5;
}

void Brick::setColor()
{
	switch (_hp)
	{
	case 1:
		getShape().setFillColor(_colors[1]);
		break;
	case 2:
		getShape().setFillColor(_colors[2]);
		break;
	case 3:
		getShape().setFillColor(_colors[3]);
		break;
	case 4:
		getShape().setFillColor(_colors[4]);
		break;
	case 5:
		getShape().setFillColor(_colors[5]);
		break;
	}
}

int Brick::getHp()
{
	return _hp;
}

bool Brick::isDisplayBrick() 
{
	if (_hp != 0)
	{
		return true;
	}
	return false;
}

//void Brick::displayBrick(float startX, float startY, sf::RenderWindow* o_window)
//{
//	if (isDisplayBrick)
//	{
//		setColor();
//		o_window->draw(getShape());
//	}
//}
//
//void Brick::displayBrickFromTxt(float startX, float startY, float gap, sf::RenderWindow* o_window, FileReader* o_fileReader)
//{
//	for (int i = 0; i < o_fileReader->getFileHeight(); i++)
//	{
//		for (int j = 0; j < o_fileReader->getFileWidth(); j++)
//		{
//			if (isDisplayBrick)
//			{
//				setColor();
//				o_window->draw(getShape());
//			}
//		}
//	}
//	
//}

