#include "State.h"

State::State(sf::RenderWindow* _window)
{
	window = _window;
	quit = false;
}

State::~State()
{}

const bool& State::GetQuit() const
{
	return quit;
}

void State::CheckForQuit()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		quit = true;
	}
}
