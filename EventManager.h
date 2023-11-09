#pragma once
#include <map>
#include <string>
#include <SFML/Graphics.hpp>
#include "Cannon.h"

typedef void (*event)();

template<typename T>
void (T::*function)();

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

	void AddEvent(sf::Event::EventType eEventType, event oFunction)
	{
		_dict[eEventType] = oFunction;
	}

	void CheckEvent(sf::Event::EventType eventName);
};

