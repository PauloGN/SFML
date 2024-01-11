#include "Game.h"

//Initializer
void Game::InitWindow()
{
	window = new sf::RenderWindow(sf::VideoMode(800, 600), "SFLM RPG");
}

//Constructor/Destructor
Game::Game():window(nullptr)
{
    InitWindow();
}

Game::~Game()
{
	delete this->window;
}

void Game::UpdateDT()
{
    dt = dtClock.restart().asSeconds();
}

//Engine functions
void Game::UpdateSFMLEvents()
{
    while (window->pollEvent(sfEvent))
    {
        if (sfEvent.type == sf::Event::Closed)
            window->close();
    }
}

void Game::Update()
{
    UpdateSFMLEvents();
}

void Game::Render()
{
    window->clear();


    window->display();
}

void Game::Run()
{
    while (window->isOpen())
    {
        UpdateDT();
        Update();
        Render();
    }
}
