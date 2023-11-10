#include "GameManager.h"
#include "EventManager.h"
GameManager* GameManager::pInstance = nullptr;

void ThrowBall()
{
	GameManager::Get()->MThrowBall();
}

GameManager::GameManager() 
{
	/*
	* INIT objets 
	*/

	/*
	* INIT events
	*/

	EventManager::Get()->AddEvent(sf::Event::EventType::MouseButtonPressed, &ThrowBall);

}

void GameManager::Update() {
	sf::Event::EventType eventName = sf::Event::MouseButtonPressed;
	//get l'event dans variable
	EventManager::Get()->CheckEvent(eventName);
}


void GameManager::MThrowBall()
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

GameManager::GameManager(bool oui)
{

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