#include "Game.h"

//Initializer
void Game::InitWindow()
{
    //Creates a SFML window and set it up using window.ini file
    std::ifstream ifs("config/window.ini");

    //local variables - Default values
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

void Game::InitStates()
{
    states.push(new GameState(window, &supportedkeys));
}

void Game::InitKeys()
{
    supportedkeys.emplace("Escape", sf::Keyboard::Key::Escape);
    supportedkeys.emplace("A", sf::Keyboard::Key::A);
    supportedkeys.emplace("S", sf::Keyboard::Key::S);
    supportedkeys.emplace("D", sf::Keyboard::Key::D);
    supportedkeys.emplace("W", sf::Keyboard::Key::W);

    std::cout << supportedkeys.at("W");

}

//Constructor/Destructor
Game::Game():window(nullptr)
{
    InitWindow();
    InitKeys();
    InitStates();
}

Game::~Game()
{
	delete this->window;
    while (!states.empty())
    {
        delete states.top();
        states.pop();
    }
}

//Engine functions
void Game::EndApplication()
{
    std::cout << "Ending Aplication \n";
}

void Game::UpdateDT()
{
    dt = dtClock.restart().asSeconds();
}

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
    if (!states.empty())
    {
        states.top()->Update(dt);

        if (states.top()->GetQuit())
        {
            states.top()->EndState();
            delete states.top();
            states.pop();
        }
    }
    //Application ends
    else
    {
        EndApplication();
        window->close();
    }

}

void Game::Render()
{
    window->clear();

    //Render items
    if (!states.empty())
    {
        states.top()->Render(window);
    }

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
