#include "GameManager.h"

#include "EventManager.h"
#include "FileReader.h"
#include "Brick.h"
#include "Ball.h"
#include "Cannon.h"
#include "Window.h"
#include "EventManager.h"
#include "GameObjectEnum.h"
GameManager* GameManager::pInstance = nullptr;

void throwBall()
{
	GameManager::Get()->MthrowBall();
}

void quit()
{
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


void GameManager::Create()
{
	if (GameManager::pInstance != nullptr)
		return;

	GameManager::pInstance = new GameManager();
	GameManager::pInstance->Initialize();
}

void GameManager::Initialize()
{
	/*
	* INIT objets
	*/
	_width = new int(1920);
	_height = new int(1080);
	_o_window = new Window(*_width, *_height);
	_window = _o_window->getWindow();
	_mousePos = new sf::Vector2i();
	_o_balls = new std::vector<Ball*>();
	o_file = new FileReader();

	// File Reader

	o_file->readFile("Files/test.txt");

	//Game Area
	_entities.resize(GoLabel::total);

	GameObject* o_leftSide = new GameObject(*_width / 4, *_height, 0.f, 0.f, 0.f, GoLabel::border);
	GameObject* o_rigthSide = new GameObject(*_width / 4 ,*_height, (*_width / 4) * 3, 0.f, 0.f, GoLabel::border);
	GameObject* o_top = new GameObject((*_width / 4) * 2, *_height * 0.1, (*_width / 4), 0.f, 0.f, GoLabel::border);

	_o_cannon = new Cannon();
	Ball* o_ball1 = new Ball();
	Ball* o_ball2 = new Ball();
	Ball* o_ball3 = new Ball();
	Ball* o_ball4 = new Ball();
	Ball* o_ball5 = new Ball();
	_o_balls->push_back(o_ball1);
	_o_balls->push_back(o_ball2);
	_o_balls->push_back(o_ball3);
	_o_balls->push_back(o_ball4);
	_o_balls->push_back(o_ball5);
	ballCounter = new int(0);

	initBrickFromTxt(50.f, 25.f, *_width / 4, *_height * 0.1 + 100.f, 10.f, _window, o_file);

	/*
	* INIT events
	*/
	EventManager::Get()->AddArea(*_width / 4.f, *_height * 0.1, (*_width / 4.f) * 3, *_height * 0.9, GameArea::Game);
	EventManager::Get()->AddArea(0, 0, 100, 100, GameArea::Restart);

	EventManager::Get()->AddEvent(GameArea::Game, sf::Event::EventType::MouseButtonPressed, &throwBall);
	EventManager::Get()->AddEvent(GameArea::Game, sf::Event::EventType::MouseMoved, &moveCannon);
	EventManager::Get()->AddEvent(GameArea::Restart, sf::Event::EventType::MouseButtonPressed, &retry);
	EventManager::Get()->AddEvent(GameArea::Quit, sf::Event::EventType::Closed, &quit);
}

void GameManager::MthrowBall()
{
	Math::Vector2 mouseVector = Math::Vector2::createVector(_o_cannon->getPos(), _mousePos->x, _mousePos->y).getNormalizeVector();

	if (mouseVector.y < 0 && Math::Vector2::leftVector.getAngle(mouseVector) >= 10 && Math::Vector2::leftVector.getAngle(mouseVector) <= 170)
	{
		if (timer > 0.3)
		{
			//_entities[GoLabel::ball].find()
			for (int i = 0; i < _o_balls->size(); i++)
			{
				if (std::find(_entities[GoLabel::ball].begin(), _entities[GoLabel::ball].end(), _o_balls->at(i)) == _entities[GoLabel::ball].end())
				{
					_o_balls->at(i)->_isDestroyed = false;
					_o_balls->at(i)->_side = "";
					_entities[GoLabel::ball].push_back(_o_balls->at(i));
					_o_cannon->fire(mouseVector, _o_balls->at(i));
					timer = o_timer.restart().asSeconds();;
					break;
				}
			}
		}
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

//GameManager::GameManager(bool oui)
//{
//
//}

void GameManager::launchGame() 
{
	sf::Clock o_clock;
	float deltaTime = 0.f;
	timer = 0.f;
	while (_window && _window->isOpen())
	{
		EventManager::Get()->Update(_window);
		for (int i = 0; i < _entities[GoLabel::ball].size(); i++)
		{
			for (int j = 0; j < _entities.size(); j++)
			{
				if(j != GoLabel::cannon && j != GoLabel::ball)
				{
					_entities[GoLabel::ball][i]->collideList(_entities[j]);
				}
				else if (j == GoLabel::ball)
				{
					for(int k = 0;k < _entities[GoLabel::ball].size();k++)
					{
						if(k != i)
						{
							_entities[GoLabel::ball][i]->collide(_entities[GoLabel::ball][k]);
						}
					}
				}
			}
		}


		for (int i = 0; i < _entities.size(); i++)
		{
			for (int j = 0; j < _entities[i].size(); j++)
			{
				if (_entities[i][j]->destroyObject()) {
					_entities[i].erase(std::remove(_entities[i].begin(), _entities[i].end(), _entities[i][j]), _entities[i].end());
				}
			}
		}
		for (int i = 0; i < _entities.size(); i++)
		{
			for (int j = 0; j < _entities[i].size(); j++)
			{
				_entities[i][j]->moveShape(deltaTime, _entities[i][j]->getVect());
			}
		}

		for (int i = 0; i < _entities[GoLabel::ball].size(); i++)
		{
			if (_entities[GoLabel::ball][i]->getPos().y > *_height)
			{
				_entities[GoLabel::ball].erase(std::remove(_entities[GoLabel::ball].begin(), _entities[GoLabel::ball].end(), _entities[GoLabel::ball][i]), _entities[GoLabel::ball].end());
			}
		}

		_window->clear();
		for (int i = 0; i < GoLabel::total; i++)
		{
			_o_window->winDraw(_entities[i]);
		}
		_window->display();

		deltaTime = o_clock.restart().asSeconds();
		timer = o_timer.getElapsedTime().asSeconds();
	}
}

void GameManager::initBrickFromTxt(float sizeX, float sizeY, float startX, float startY, float gap, sf::RenderWindow* o_window, FileReader* o_fileReader)
{
	std::vector<std::vector<int>> tabFile = o_fileReader->getFile();

	float width = 0.f;

	for (int j = 0; j < o_fileReader->getFileWidth(); j++)
	{
		if (tabFile[0][j] != -1)
		{
			width += sizeX + gap;
		}
		else
		{
			width += gap;
		}
	}

	if ((int) width > *_width / 2)
	{
		std::cout << "ERROR, your file for this level is too big" << std::endl;
		return; 
	}

	float posX = 1920 / 2 - width / 2;
	float x = posX;
	float y = startY;


	for (int i = 0; i < o_fileReader->getFileHeight(); i++)
	{
		for (int j = 0; j < o_fileReader->getFileWidth(); j++)
		{
			if (tabFile[i][j] != -1)
			{
				if (tabFile[i][j] != 0)
				{
					_listBricks.push_back(new Brick(sizeX, sizeY, x, y, _speed, tabFile[i][j]));
				}
				x += sizeX + gap;
			}
			else
			{
				x += gap;
			}
		}
		x = posX;
		y += sizeY + gap;
	}

}

void GameManager::addToEntity(int iLabel, GameObject* o_gameObject)
{
	if (iLabel == -1)
		return;

	_entities[iLabel].push_back(o_gameObject);
}