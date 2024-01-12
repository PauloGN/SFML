#include "Game.h"

//Initializer
void Game::InitWindow()
{
    //Creates a SFML window and set it up using window.ini file
    std::ifstream ifs("config/window.ini");

    //local variables
    sf::VideoMode win_bounds(400, 400);
    std::string title = "My Game";
    unsigned framerate_limit = 120;
    bool vertical_sync_enabled = false;

    if (ifs.is_open())
    {
        std::getline(ifs, title);
        ifs >> win_bounds.width >> win_bounds.height;
        ifs >> framerate_limit;
        ifs >> vertical_sync_enabled;
    }

    ifs.close();

	window = new sf::RenderWindow(win_bounds, title);
    window->setFramerateLimit(framerate_limit);
    window->setVerticalSyncEnabled(vertical_sync_enabled);
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
