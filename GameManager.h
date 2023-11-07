#pragma once

class GameManager
{
private:
	static GameManager* pInstance;
	GameManager();



public:
	static void Initialize() 
	{
		if (pInstance != nullptr)
			return;

		pInstance = new GameManager();
	}

	static GameManager* Get() 
	{
		return pInstance;
	}
	void Update();
};

