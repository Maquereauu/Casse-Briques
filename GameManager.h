#pragma once
#include "EventManager.h"
#include <SFML/Graphics.hpp>
class GameObject;
class Ball; 
class Cannon; 
class Window; 
class FileReader;
class Brick;
class GameManager
{
private:
	int _width;
	int _height;
	std::vector<Ball*> _o_balls;
	Window* _o_window;
	Cannon* _o_cannon;
	static GameManager* pInstance;
	GameManager();
	sf::Vector2i* _mousePos;
	std::vector<GameObject*>* _entities;
	sf::RenderWindow* _window;

public:
	
	static void Initialize() 
	{
		if (pInstance != nullptr)
			return;

		pInstance = new GameManager();
	}

	static GameManager* Get() 
	{
		return pInstance;
	}
	void Update(EventManager::GameArea area, sf::Event::EventType eventName);

	void MthrowBall();
	void Mretry();
	void Mquit();
	void MmoveCannon();


	std::vector<Brick*> _listBricks; //
	float _speed = 90.f; //
	void displayBricks(sf::RenderWindow* o_window, std::vector<Brick*> listBricks);
	//GameManager(bool oui); //
	void launchGame();
	void initBrickFromTxt(float sizeX, float sizeY, float startX, float startY, float gap, sf::RenderWindow* o_window, FileReader* o_fileReader); //
	 
};


