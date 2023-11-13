#include "GameManager.h"
#include "FileReader.h"
#include "Brick.h"
#include "Ball.h"
#include "Cannon.h"
#include "Window.h"

GameManager* GameManager::pInstance = nullptr;

void throwBall()
{
	GameManager::Get()->MthrowBall();
}

void quit()
{
	std::cout << "yo" << std::endl;
	GameManager::Get()->Mquit();
}

void retry()
{
	GameManager::Get()->Mretry();
}

void moveCannon()
{
	GameManager::Get()->MmoveCannon();
}

GameManager::GameManager() 
{
	_width = 1920;
	_height = 1080;
	_o_window = new Window(_width, _height);
	_window = _o_window->getWindow();
	_mousePos = new sf::Vector2i();
	_entities = new std::vector<GameObject*>();
	/*
	* INIT objets 
	*/

	//Game Area
	GameObject* o_leftSide = new GameObject(_width / 4, _height, 0.f, 0.f, 0.f);
	GameObject* o_rigthSide = new GameObject(_width / 4, _height, (_width / 4) * 3, 0.f, 0.f);
	GameObject* o_top = new GameObject((_width / 4) * 2, _height*0.2, (_width / 4), 0.f, 0.f);


	_o_cannon = new Cannon(50.f, 100.f, _width/2, _height*0.8, 90.f);
	_o_balls.resize(3);

	/*
	* INIT events
	*/
	EventManager::Get()->AddEvent(EventManager::GameArea::Game,sf::Event::EventType::MouseButtonPressed, &throwBall);
	EventManager::Get()->AddEvent(EventManager::GameArea::Game, sf::Event::EventType::MouseMoved, &moveCannon);
	EventManager::Get()->AddEvent(EventManager::GameArea::Restart, sf::Event::EventType::MouseButtonPressed, &retry);
	EventManager::Get()->AddEvent(EventManager::GameArea::Quit, sf::Event::EventType::Closed, &quit);
}

void GameManager::Update(EventManager::GameArea area ,sf::Event::EventType eventName) {
	//get l'event dans variable
	EventManager::Get()->CheckEvent(area,eventName);
}


void GameManager::MthrowBall()
{
	_o_cannon->fire(Math::Vector2::createVector(_o_cannon->getPos(), _mousePos->x, _mousePos->y).getNormalizeVector(),_o_balls[0]);
}

void GameManager::Mretry()
{
	/*

	*/
}

void GameManager::Mquit()
{
	std::cout << "yo" << std::endl;
	_window->close();
}

void GameManager::MmoveCannon()
{
	/*

	*/
}



void GameManager::displayBricks(sf::RenderWindow* o_window, std::vector<Brick*> listBricks)
{
	for (int i = 0; i < listBricks.size(); i++)
	{
		listBricks[i]->displayBrick(o_window);
	}
}

//GameManager::GameManager(bool oui)
//{
//
//}

void GameManager::launchGame() 
{
	sf::Clock o_clock;
	float deltaTime = 0.f;
	while (_window && _window->isOpen())
	{
		sf::Event event;
		while (_window->pollEvent(event))
		{
			*_mousePos = sf::Mouse::getPosition(*(_window));
			if ((_mousePos->x >= _width / 4 && _mousePos->x <= (_width / 4) * 3) && (_mousePos->y >= _height * 0.2 && _mousePos->y <= _height * 0.8))
			{
				Update(EventManager::GameArea::Game,event.type);
			}
			else if((_mousePos->x >= 0 && _mousePos->x <= 100) && (_mousePos->y >= 0 && _mousePos->y <= 100)){
				Update(EventManager::GameArea::Restart, event.type);
			}
			else {
				Update(EventManager::GameArea::Quit, event.type);
			}
		}



		for (int i = 0; i < _entities->size(); i++)
		{
			_entities->at(i)->moveShape(deltaTime, _entities->at(i)->getVect());
		}


		_window->clear();
		_o_window->winDraw(_entities);
		_window->display();

		deltaTime = o_clock.restart().asSeconds();
	}
}

void GameManager::initBrickFromTxt(float sizeX, float sizeY, float startX, float startY, float gap, sf::RenderWindow* o_window, FileReader* o_fileReader)
{
	std::vector<std::vector<int>> tabFile = o_fileReader->getFile();

	float x = startX;
	float y = startY;

	for (int i = 0; i < o_fileReader->getFileHeight(); i++)
	{
		for (int j = 0; j < o_fileReader->getFileWidth(); j++)
		{
			_listBricks.push_back(new Brick(sizeX, sizeY, x, y, _speed, tabFile[i][j]));
			x += sizeX + gap;
		}
		x = startX;
		y += sizeY + gap;
	}

}