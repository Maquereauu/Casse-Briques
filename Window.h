#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
class Window
{
private:
	int _sizeX;
	int _sizeY;
	sf::RenderWindow* _window;
public:
	Window(int sizeX,int sizeY);
	void winDraw(std::vector<GameObject*>* list);
};

