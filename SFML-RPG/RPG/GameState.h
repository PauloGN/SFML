#pragma once
#include "State.h"
class GameState : public State
{

private:

public:

	GameState(sf::RenderWindow* _window);
	virtual ~GameState();

	virtual void EndState() override;
	void Update(const float& _dt) override;
	void Render(sf::RenderTarget* _target = nullptr) override;
};

