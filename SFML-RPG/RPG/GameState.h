#pragma once
#include "State.h"
class GameState : public State
{

private:

	Entity player;

public:

	GameState(sf::RenderWindow* _window);
	virtual ~GameState();
	
	void EndState() override;
	void UpdateKeyBinds(const float& _dt) override;
	void Update(const float& _dt) override;
	void Render(sf::RenderTarget* _target = nullptr) override;
};

