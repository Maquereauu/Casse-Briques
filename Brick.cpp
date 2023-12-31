#include "Brick.h"

#include <SFML/Graphics.hpp>
#include "GameObjectEnum.h"
Brick::Brick(float sizeX, float sizeY, float posX, float posY, float speed, int hp) : GameObject(sizeX, sizeY, posX, posY, speed,GoLabel::brick) // create a brick with is parent
{
	_colors = { {1, sf::Color::Red}, {2, sf::Color::Yellow}, {3, sf::Color::Blue}, {4, sf::Color::Green}, {5, sf::Color::White} };
	_hp = hp;
	_maxHp = hp;
	setColor();
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

void Brick::isDisplayBrick() 
{
	// verification if the brick have more than 0 hp
	if (_hp == 0)
	{
		_isDestroyed = true;
	}
}

void Brick::minusHp()
{
	_hp -= 1;
	setColor();
}

void Brick::onCollisionEnter(GameObject* object)
{
	this->minusHp();
	isDisplayBrick();
}

void Brick::heal()
{
	_hp = _maxHp;
	setColor();
}
