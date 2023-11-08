#pragma once
#include <map>
#include <string>
#include <SFML/Graphics.hpp>
#include "Cannon.h"

typedef void (*event)();

//typedef void (Cannon::*function)();

void A();
void B();

class EventManager
{
private:
	static EventManager* pInstance;
	EventManager();
public:
	std::map<sf::Event::EventType, event> _dict;
	//std::map<sf::Event::EventType, function> _dictmet;
	static void Initialize()
	{
		if (pInstance != nullptr)
			return;

		pInstance = new EventManager();
	}

	static EventManager* Get()
	{
		return pInstance;
	}
	void CheckEvent(sf::Event::EventType eventName);
};

