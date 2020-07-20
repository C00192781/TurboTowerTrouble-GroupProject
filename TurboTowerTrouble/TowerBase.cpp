#include "TowerBase.h"
#include <iostream>
TowerBase::TowerBase()
{
	rect.setPosition(-100, -100);
	rect.setFillColor(sf::Color(50, 255, 0, 80));
	selected = false;

}
TowerBase::TowerBase(sf::Vector2<int>p) :position(p)
{
	rect.setPosition(p.x, p.y);
	rect.setSize(sf::Vector2f(50, 50));
	rect.setFillColor(sf::Color(50, 255, 0, 80));
	selected = false;
}

void TowerBase::SetPosition(sf::Vector2<int>p)
{
	rect.setPosition(p.x, p.y);
}

sf::Vector2f TowerBase::getPosition()
{
	return position;
}

void TowerBase::SetSize(float width, float height)
{
	rect.setSize(sf::Vector2f(width, height));
}

void TowerBase::Draw(sf::RenderWindow *window)
{
	if (selected == true)
	{
		window->draw(rect);
	}
}

void TowerBase::SetSelected(bool isSelected)
{
	selected = isSelected;
}