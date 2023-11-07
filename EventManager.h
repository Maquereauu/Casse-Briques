#pragma once
#include <map>
#include <string>

typedef void (*event)();

void A();
void B();

class EventManager
{
private:
	static EventManager* pInstance;
	EventManager();
public:
	std::map<std::string, event> _dict;
	EventManager();
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
	void CheckEvent(std::string eventName);
};

