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


class Entity
{
private:

protected:

	sf::RectangleShape shape;
	float movementSpeed;

public:
	Entity();
	virtual ~Entity();

	//Base functions
	virtual void Move(const float& dt, const float dir_x, const float dir_y);
	virtual void Move(const float dir_x, const float dir_y);

	virtual void Update(const float& dt);
	virtual void Render(sf::RenderTarget* target);

};

