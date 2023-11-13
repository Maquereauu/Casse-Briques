#pragma once
#include <map>
#include <SFML/Graphics.hpp>

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
		Restart,
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

