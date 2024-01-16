#include "GameState.h"

void GameState::InitKeyBinds()
{

	Keybinds.emplace("MOVE_LEFT", suportedkeys->at("A"));
	Keybinds.emplace("MOVE_RIGHT", suportedkeys->at("D"));
	Keybinds.emplace("MOVE_UP", suportedkeys->at("W"));
	Keybinds.emplace("MOVE_DOWN", suportedkeys->at("S"));


}

GameState::GameState(sf::RenderWindow* _window, std::map<std::string, int>* _supportedkeys) :
	State(_window, _supportedkeys)
{
	InitKeyBinds();
}

GameState::~GameState()
{}

void GameState::EndState()
{
	std::cout << "Ending Game State" << std::endl;
}

void GameState::UpdateInputs(const float& _dt)
{
	CheckForQuit();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(Keybinds.at("MOVE_LEFT"))))
	{
		player.Move(_dt, -1.0f, 0.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(Keybinds.at("MOVE_RIGHT"))))
	{
		player.Move(_dt, 1.0f, 0.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(Keybinds.at("MOVE_UP"))))
	{
		player.Move(_dt, 0.0f, -1.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(Keybinds.at("MOVE_DOWN"))))
	{
		player.Move(_dt, 0.0f, 1.0f);
	}

}

void GameState::Update(const float& _dt)
{
	UpdateInputs(_dt);

	player.Update(_dt);


}

void GameState::Render(sf::RenderTarget* _target)
{
	if (!_target)
	{
		_target = window;
	}

	player.Render(_target);
}
