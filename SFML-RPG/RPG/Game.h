#pragma once
#include "GameState.h"

class Game
{

private:

	//Variables
	sf::RenderWindow* window;
	sf::Event sfEvent;

	sf::Clock dtClock;
	float dt;

	//state is abstract, then we are going to have a stack of pointers to various states, where the top is always the active one.
	std::stack<State*> states;

	//Initialization
	void InitWindow();
	void InitStates();

public:

	//Constructor/Destructor
	Game();
	virtual ~Game();

	//***Engine Function***\\

	//Engine
	void EndApplication();

	//Updates
	void UpdateDT();
	void UpdateSFMLEvents();
	void Update();

	//render
	void Render();

	//core
	void Run();
};