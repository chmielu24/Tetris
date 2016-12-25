#pragma once
#include "DrawUpdate.h"
#include <SFML/Window/Event.hpp>

class Scene : public DrawUpdate
{
public:
	Scene() = default;
	virtual ~Scene() = default;

	virtual void Events(sf::Event&) = 0;
};