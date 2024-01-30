#pragma once
#include "GameState.h"
class MainMenuState :  public State
{

private:

	//Functions
	sf::RectangleShape background;
	void InitKeyBinds() override;

public:

	MainMenuState(sf::RenderWindow* _window, std::map<std::string, int>* _supportedkeys);
	virtual ~MainMenuState();

	void EndState() override;
	void UpdateInputs(const float& _dt) override;
	void Update(const float& _dt) override;
	void Render(sf::RenderTarget* _target = nullptr) override;

};