#include "EventManager.h"

EventManager* EventManager::pInstance = nullptr;

EventManager::EventManager() {
	//Initialize();
	//_dict[sf::Event::MouseButtonPressed] = &A;
	//_dict[sf::Event::Closed] = &B;
	//_dictmet[sf::Event::Closed] = &Cannon::cannonMove;
}


void A() 
{
	//Cannon.Fire()
}

void B()
{
	//window.close en changeant une variable membre
}

void EventManager::CheckEvent(GameArea area,sf::Event::EventType eventName){
	if (_dict.find(area) != _dict.end() && _dict[area].find(eventName) != _dict[area].end()) {
		_dict[area][eventName]();
	}
}