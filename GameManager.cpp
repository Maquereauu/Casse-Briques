#include "GameManager.h"
#include "EventManager.h"
#include "FileReader.h"
#include "Brick.h"
#include "Ball.h"
#include "Cannon.h"
#include "Window.h"
#include "EventManager.h"
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
	_width = new int(1920);
	_height = new int(1080);
	_o_window = new Window(*_width, *_height);
	_window = _o_window->getWindow();
	_mousePos = new sf::Vector2i();
	_entities = new std::vector<GameObject*>();
	_o_balls = new std::vector<Ball*>();
	/*
	* INIT objets 
	*/

	//Game Area
	GameObject* o_leftSide = new GameObject(*_width / 4, *_height, 0.f, 0.f, 0.f);
	GameObject* o_rigthSide = new GameObject(*_width / 4, *_height, (*_width / 4) * 3, 0.f, 0.f);
	GameObject* o_top = new GameObject((*_width / 4) * 2, *_height*0.2, (*_width / 4), 0.f, 0.f);


	_o_cannon = new Cannon(50.f, 100.f, *_width/2, *_height*0.8, 90.f);
	Ball* o_ball1 = new Ball();
	Ball* o_ball2 = new Ball();
	Ball* o_ball3 = new Ball();
	_o_balls->push_back(o_ball1);
	_o_balls->push_back(o_ball2);
	_o_balls->push_back(o_ball3);
	ballCounter = new int(0);
	_entities->push_back(o_leftSide);
	_entities->push_back(o_rigthSide);
	_entities->push_back(o_top);
	_entities->push_back(o_ball1);
	_entities->push_back(o_ball2);
	_entities->push_back(o_ball3);
	_entities->push_back(_o_cannon);
	std::cout << *ballCounter << std::endl;

	/*
	* INIT events
	*/
	EventManager::Get()->AddArea(*_width / 4.f,*_height * 0.2, (*_width / 4.f)*3,*_height*0.8,GameArea::Game);
	EventManager::Get()->AddArea(0,0,100,100,GameArea::Restart);

	EventManager::Get()->AddEvent(GameArea::Game,sf::Event::EventType::MouseButtonPressed, &throwBall);
	EventManager::Get()->AddEvent(GameArea::Game, sf::Event::EventType::MouseMoved, &moveCannon);
	EventManager::Get()->AddEvent(GameArea::Restart, sf::Event::EventType::MouseButtonPressed, &retry);
	EventManager::Get()->AddEvent(GameArea::Quit, sf::Event::EventType::Closed, &quit);
}


void GameManager::MthrowBall()
{
	Math::Vector2 mouseVector = Math::Vector2::createVector(_o_cannon->getPos(), _mousePos->x, _mousePos->y).getNormalizeVector();
	if (mouseVector.y < 0 && Math::Vector2::leftVector.getAngle(mouseVector) >= 10 && Math::Vector2::leftVector.getAngle(mouseVector) <= 170)
	{
		_o_cannon->fire(mouseVector, _o_balls->at(*ballCounter));
		*ballCounter += 1;
		*ballCounter %= 3;
	}
}

void GameManager::Mretry()
{
	/*

	*/
}

void GameManager::Mquit()
{
	_window->close();
}

void GameManager::MmoveCannon()
{
	Math::Vector2 mouseVector = Math::Vector2::createVector(_o_cannon->getPos(), _mousePos->x, _mousePos->y).getNormalizeVector();
	if (mouseVector.y < 0 && Math::Vector2::leftVector.getAngle(mouseVector) >= 15 && Math::Vector2::leftVector.getAngle(mouseVector) <= 165)
	{
		_o_cannon->move(mouseVector);
	}
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
		EventManager::Get()->Update(_window);

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