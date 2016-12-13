#pragma once
#include <SFML\Graphics\Drawable.hpp>


class DrawUpdate : public sf::Drawable
{
public:
	virtual void Update() = 0;
	virtual ~DrawUpdate() {};
};