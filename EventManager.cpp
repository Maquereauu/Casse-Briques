#include "EventManager.h"
EventManager* EventManager::pInstance = nullptr;

EventManager::EventManager() {
	Initialize();
	_dict["MouseEvent"] = &A;
	_dict["EscapeEvent"] = &B;
}

void A() 
{
	//Ball.Launch
}

void B()
{
	//window.close en changeant une variable membre
}

void EventManager::CheckEvent(std::string eventName){
	_dict[eventName];
}