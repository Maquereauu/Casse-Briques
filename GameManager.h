#pragma once

#include "FileReader.h"
#include "Brick.h"

class GameManager
{
private:
	static GameManager* pInstance;
	GameManager();


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
	void Update();

	void MThrowBall();




	std::vector<Brick*> _listBricks; //
	float _speed = 90.f; //
	void displayBricks(sf::RenderWindow* o_window, std::vector<Brick*> listBricks);
	GameManager(bool oui); //
	void initBrickFromTxt(float sizeX, float sizeY, float startX, float startY, float gap, sf::RenderWindow* o_window, FileReader* o_fileReader); //
	 
};


