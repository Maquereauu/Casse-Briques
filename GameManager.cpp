#include "GameManager.h"
#include "EventManager.h"
GameManager* GameManager::pInstance = nullptr;

GameManager::GameManager() {
	Initialize();
}

void GameManager::Update() {
	sf::Event::EventType eventName = sf::Event::MouseButtonPressed;
	//get l'event dans variable
	EventManager::Get()->CheckEvent(eventName);
}