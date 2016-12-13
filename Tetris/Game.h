#pragma once
#include <vector>
#include <SFML\Graphics.hpp>
#include "DrawUpdate.h"
#include "Time.h"

class Game
{
public:
	Game();
	virtual ~Game();

	void Start();
	void Update();
	void Renderer();

private:
	sf::RenderWindow *rWindow;
	std::vector<DrawUpdate*> vGameObjects;

	Time *time;
	
};