#pragma once
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
	std::vector<Ball*>* _o_balls;
	Window* _o_window;
	Cannon* _o_cannon;
	static GameManager* pInstance;
	sf::Clock o_timer;
	float timer;
	GameManager() {};
	void Initialize();

	sf::RenderWindow* _window;
	int* ballCounter;

	sf::Font _font;
public:
	int* _width;
	int* _height;
	std::vector<std::vector<GameObject*>> _entities;
	sf::Vector2i* _mousePos;
	FileReader* o_file;

	typedef enum GameArea
	{
		None,
		Game,
		Restart,
		Quit
	};

	static void Create();

	static GameManager* Get() 
	{
		return pInstance;
	}

	void MthrowBall();
	void Mretry();
	void Mquit();
	bool Mwin();
	void MmoveCannon();


	std::vector<Brick*> _listBricks;
	float _speed = 90.f; //
	void launchGame();
	void addToEntity(int iLabel,GameObject* o_gameObject);
	void initBrickFromTxt(float sizeX, float sizeY, float startX, float startY, float gap, sf::RenderWindow* o_window, FileReader* o_fileReader); //
	 
};


