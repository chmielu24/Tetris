#include "Game.h"

Game::Game() :
	shape(100.0f)
{
	rWindow = new sf::RenderWindow(sf::VideoMode(1280, 720), "Tetris", sf::Style::Default);

	sf::View view;
	view = rWindow->getView();
	view.setSize(1280, 720);
	view.setCenter(1280 / 2, 720 / 2);

	rWindow->setView(view);

	shape.setFillColor(sf::Color::Green);
	shape.setPosition(1280 / 2 - 100, 720 / 2 - 100);
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
		rWindow->close();

	sf::Event event;
	while (rWindow->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			rWindow->close();
	}
}


void Game::Renderer()
{
	rWindow->clear();
	rWindow->draw(shape);
	rWindow->display();
}
