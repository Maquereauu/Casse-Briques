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
	typedef enum GameArea 
	{
		None,
		Game,
		Reset,
		Quit
	};

	std::map<GameArea,std::map<sf::Event::EventType, event>> _dict;
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

	void AddEvent(GameArea area,sf::Event::EventType eEventType, event oFunction)
	{
		_dict[area][eEventType] = oFunction;
	}

	void CheckEvent(GameArea area,sf::Event::EventType eventName);
};

