#include "Game.h"



Game::Game()
{
	rWindow = new sf::RenderWindow(sf::VideoMode(1280, 720), "Tetris", sf::Style::Default);

	sf::View view;
	view = rWindow->getView();
	view.setSize(1280, 720);
	view.setCenter(1280 / 2, 720 / 2);

	rWindow->setView(view);

	time = new Time(true, 1200, 10);

	vGameObjects.push_back(time);
}

Game::~Game()
{
	free(rWindow);
}


void Game::Start()
{
	while (rWindow->isOpen())
	{
		Update();
		Renderer();
	}
}

void Game::Update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		rWindow->close();
	}

	sf::Event event;
	while (rWindow->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			rWindow->close();
	}

	for each (auto& var in vGameObjects)
	{
		var->Update();
	}
}


void Game::Renderer()
{
	rWindow->clear();

	for each (auto var in vGameObjects)
	{
		rWindow->draw(*var);
	}

	rWindow->display();
}
