#include "Game.h"
#include <time.h>
#include <chrono>
#include <thread>

Game::Game() :
	m_Settegins(new Settegins("Settegins.ini")),
	m_Thread(new sf::Thread(&Game::RendererThread, this))
{
	if(m_Settegins->Get().FullScreen)
		m_Window = std::make_unique<sf::RenderWindow>(sf::VideoMode(m_Settegins->Get().ResX, m_Settegins->Get().ResY), "Tetris", sf::Style::Fullscreen);
	else
		m_Window = std::make_unique<sf::RenderWindow>(sf::VideoMode(m_Settegins->Get().ResX, m_Settegins->Get().ResY), "Tetris", sf::Style::Default);

	m_Time = std::make_unique<Time>(m_Settegins->Get().ShowFPS, 1150, 10),
	i_FPSMax = m_Settegins->Get().MaxFPS;

	sf::View view;
	view = m_Window->getView();
	view.setSize(1280, 720);
	view.setCenter(1280 / 2, 720 / 2);
	m_Window->setView(view);

	m_Window->setFramerateLimit(i_FPSMax);

	v_GameObjects.push_back( m_Time.get() );
}

Game::~Game()
{
}


void Game::Start()
{
	m_Window->setActive(false);
	m_Thread->launch();

	auto timeDelay = std::chrono::milliseconds(1000 / i_FPSMax);
	auto t = std::chrono::system_clock::now();

	while (m_Window->isOpen())
	{
		t += timeDelay;
		std::this_thread::sleep_until(t);
		
		Update();
	}
}

void Game::Update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		m_Window->close();
	}

	sf::Event event;
	while (m_Window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			m_Window->close();
	}


	for each (auto& var in v_GameObjects)
	{
		var->Update();
	}

}


void Game::RendererThread()
{
	while (m_Window->isOpen())
	{
		m_Window->clear(sf::Color::Black);

		for each (auto& var in v_GameObjects)
		{
			m_Window->draw(*var);
		}

		m_Window->display();
	}
}

