#pragma once
#include <SFML/Window/Event.hpp>
#include "DrawUpdate.h"


class Scene : public DrawUpdate
{
public:
	Scene() = default;
	virtual ~Scene() = default;

	virtual void Events(sf::Event&) = 0;
};