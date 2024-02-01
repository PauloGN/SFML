#pragma once
#include "MainMenuState.h"

class Game
{

private:

	//Variables
	sf::RenderWindow* window;
	sf::Event sfEvent;

	sf::Clock dtClock;
	float dt;

	//state is an abstract class, then we are going to have a stack of pointers to various states, where the top is always the active one.
	std::stack<State*> states;
	std::map<std::string, int> supportedkeys;

	//Initialization
	void InitWindow();
	void InitStates();
	void InitKeys();

public:

	//Constructor/Destructor
	Game();
	virtual ~Game();

	//***Engine Function***\\

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