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