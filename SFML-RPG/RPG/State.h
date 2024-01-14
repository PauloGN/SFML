#pragma once
#include "Entity.h"

class State
{
private:

	sf::RenderWindow* window;
	std::vector<sf::Texture> texture;
	bool quit;

public:
	State(sf::RenderWindow* _window);
	virtual ~State();

	const bool& GetQuit() const;
	virtual void CheckForQuit();

	virtual void EndState() = 0;
	virtual void UpdateKeyBinds(const float& _dt) = 0;
	virtual void Update(const float& _dt) = 0;
	virtual void Render(sf::RenderTarget* _target = nullptr) = 0;
};

