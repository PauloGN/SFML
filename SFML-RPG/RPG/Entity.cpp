#include "Entity.h"

Entity::Entity()
{
	shape.setSize(sf::Vector2f(50.f, 50.f));
	movementSpeed = 100.0f;
}

Entity::~Entity()
{}

void Entity::Move(const float& dt, const float dir_x, const float dir_y)
{
	shape.move(dir_x * dt * movementSpeed, dir_y * dt * movementSpeed);
}

void Entity::Move(const float dir_x, const float dir_y)
{
	shape.move(dir_x * movementSpeed, dir_y * movementSpeed);
}

void Entity::Update(const float& dt)
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		Move(dt, -1.0f, 0.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		Move(dt, 1.0f, 0.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		Move(dt, 0.0f, -1.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		Move(dt, 0.0f, 1.0f);
	}
}

void Entity::Render(sf::RenderTarget* target)
{
	target->draw(shape);
}
