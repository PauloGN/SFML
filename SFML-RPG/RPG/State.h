#pragma once

#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>
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

	std::vector<sf::Texture> texture;


public:
	State();
	virtual ~State();

	virtual void Update() = 0;
	virtual void Render() = 0;
};

