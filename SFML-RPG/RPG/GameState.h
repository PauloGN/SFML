#pragma once
#include "State.h"
class GameState : public State
{

private:

	Entity player;


	//Functions
	void InitKeyBinds() override;

public:

	GameState(sf::RenderWindow* _window, std::map<std::string, int>* _supportedkeys);
	virtual ~GameState();
	
	void EndState() override;
	void UpdateInputs(const float& _dt) override;
	void Update(const float& _dt) override;
	void Render(sf::RenderTarget* _target = nullptr) override;
};

