#pragma once
#include "State.h"

class Game
{

private:

	//Variables
	sf::RenderWindow* window;
	sf::Event sfEvent;

	sf::Clock dtClock;
	float dt;

	//Initialization
	void InitWindow();

public:

	//Constructor/Destructor
	Game();
	virtual ~Game();

	//Engine Function
	void UpdateDT();
	void UpdateSFMLEvents();
	void Update();
	void Render();
	void Run();
};