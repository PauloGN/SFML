#include "State.h"

State::State(sf::RenderWindow* _window, std::map<std::string, int>* _suportedkeys):
	window(_window), quit(false), suportedkeys(_suportedkeys)
{


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