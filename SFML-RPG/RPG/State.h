#pragma once

#include <ctime>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <stack>
#include <vector>
//SFLM
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"


class State
{
private:

	sf::RenderWindow* window;
	std::vector<sf::Texture> texture;


public:
	State(sf::RenderWindow* _window);
	virtual ~State();

	virtual void EndState() = 0;

	virtual void Update(const float& _dt) = 0;
	virtual void Render(sf::RenderTarget* _target = nullptr) = 0;
};

