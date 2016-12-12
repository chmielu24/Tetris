#pragma once

#include <SFML\Graphics.hpp>


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
	
};