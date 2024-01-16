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


}

void Entity::Render(sf::RenderTarget* target)
{
	target->draw(shape);
}
