#pragma once
#include "Entity.h"

class State
{
protected:

	sf::RenderWindow* window;
	std::map<std::string, int>* supportedkeys;
	//each state is going to have its own leybinds
	std::map<std::string, int> Keybinds;
	bool quit;

	//Resourcers
	std::vector<sf::Texture> texture;

private:

	//Functions
	virtual void InitKeyBinds() = 0;

public:
	State(sf::RenderWindow* _window, std::map<std::string, int>* _suportedkeys);
	virtual ~State();

	const bool& GetQuit() const;
	virtual void CheckForQuit();

	virtual void EndState() = 0;
	virtual void UpdateInputs(const float& _dt) = 0;
	virtual void Update(const float& _dt) = 0;
	virtual void Render(sf::RenderTarget* _target = nullptr) = 0;
};