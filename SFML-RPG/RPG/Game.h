#pragma once

#include <iostream>
#include <ctime>
//SFLM
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"

class Game
{

private:

	//Variables
	sf::RenderWindow* window;
	sf::Event sfEvent;

	//Initialization
	void InitWindow();

public:

	//Constructor/Destructor
	Game();
	virtual ~Game();

	//Engine Function
	void UpdateSFMLEvents();
	void Update();
	void Render();
	void Run();
};