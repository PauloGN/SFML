#include "MainMenuState.h"

void MainMenuState::InitKeyBinds()
{
	//std::ifstream ifs("config/GS_Keybinds.ini");

	//if (ifs.is_open())
	//{
	//	std::string key_Func;
	//	std::string keyboard;

	//	while (ifs >> key_Func >> keyboard)
	//	{
	//		//Keybinds["MOVE_LEFT"] = supportedkeys->at("A");
	//		Keybinds[key_Func] = supportedkeys->at(keyboard);
	//		std::cout << key_Func << " -> " << keyboard << "\n";
	//	}
	//}

	//ifs.close();
}

MainMenuState::MainMenuState(sf::RenderWindow* _window, std::map<std::string, int>* _supportedkeys) :
	State(_window, _supportedkeys)
{
	InitKeyBinds();

	background.setSize(sf::Vector2f(window->getSize()));
	background.setFillColor(sf::Color::Magenta);
}

MainMenuState::~MainMenuState()
{}

void MainMenuState::EndState()
{
	std::cout << "Ending Game State" << std::endl;
}

void MainMenuState::UpdateInputs(const float& _dt)
{
	CheckForQuit();
}

void MainMenuState::Update(const float& _dt)
{
	UpdateInputs(_dt);
}

void MainMenuState::Render(sf::RenderTarget* _target)
{
	if (!_target)
	{
		_target = window;
	}


	_target->draw(background);
}