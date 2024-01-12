#include "GameState.h"

GameState::GameState(sf::RenderWindow* _window) :
	State(_window)
{}

GameState::~GameState()
{}

void GameState::EndState()
{}

void GameState::Update(const float& _dt)
{
	std::cout << "Hello from GameState" << std::endl;
}

void GameState::Render(sf::RenderTarget* _target)
{}
