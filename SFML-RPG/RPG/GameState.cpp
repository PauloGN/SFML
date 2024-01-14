#include "GameState.h"

GameState::GameState(sf::RenderWindow* _window) :
	State(_window)
{}

GameState::~GameState()
{}

void GameState::EndState()
{
	std::cout << "Ending Game State" << std::endl;
}

void GameState::UpdateKeyBinds(const float& _dt)
{
	CheckForQuit();

}

void GameState::Update(const float& _dt)
{
	UpdateKeyBinds(_dt);

	player.Update(_dt);


}

void GameState::Render(sf::RenderTarget* _target)
{
	player.Render(_target);
}
