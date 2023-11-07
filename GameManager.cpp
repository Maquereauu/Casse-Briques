#include "GameManager.h"
#include "EventManager.h"
GameManager* GameManager::pInstance = nullptr;

GameManager::GameManager() {
	Initialize();
}

void GameManager::Update() {
	std::string eventName = "MouseEvent";
	//get l'event dans variable
	EventManager::Get()->CheckEvent(eventName);
}