#include <time.h>
#include "Game.h"
#include "SceneMenu.h"
#include "SceneGame.h"
#include "SceneOptions.h"

Game::Game() :
	m_Settegins(new Settegins("Settegins.ini")),
	m_Thread(new sf::Thread(&Game::RendererThread, this)),
	m_Scene(new SceneMenu()),
	b_rendererStoped(false),
	b_stopRenderer(false)
{

	if(m_Settegins->Get().FullScreen)
		m_Window = std::make_unique<sf::RenderWindow>(sf::VideoMode(m_Settegins->Get().ResX, m_Settegins->Get().ResY), "Tetris", sf::Style::Fullscreen);
	else
		m_Window = std::make_unique<sf::RenderWindow>(sf::VideoMode(m_Settegins->Get().ResX, m_Settegins->Get().ResY), "Tetris", sf::Style::Default);

	m_Time = std::make_unique<Time>(m_Settegins->Get().ShowFPS, 560, -340);

	sf::View view;
	view = m_Window->getView();
	view.setSize(1280, 720);
	view.setCenter(0, 0);
	m_Window->setView(view);

	m_Window->setFramerateLimit(m_Settegins->Get().MaxFPS);
	timeDelay = std::chrono::milliseconds(1000 / m_Settegins->Get().MaxFPS);


	Bind();
}

void Game::Bind()
{
	v_GameObjects.clear();
	v_GameObjects.push_back(m_Scene.get());
	v_GameObjects.push_back(m_Time.get());
}


void Game::Start()
{
	m_Window->setActive(false);
	m_Thread->launch();

	auto t = std::chrono::system_clock::now();

	while (m_Window->isOpen())
	{
		t += timeDelay;
		std::this_thread::sleep_until(t);
		
		Events();
		Update();
	}
}

void Game::LoadScene(std::string name)
{
	b_stopRenderer = true;

	while (Instance().b_rendererStoped == false)
		sf::sleep(sf::milliseconds(10));

	if (name == "game")
	    Instance().m_Scene.reset(new SceneGame());
	else if (name == "menu")
		Instance().m_Scene.reset(new SceneMenu());
	else if (name == "options")
		Instance().m_Scene.reset(new SceneOptions());

	Bind();
	b_stopRenderer = false;
	b_rendererStoped = false;
}

void Game::ExitGame()
{
	m_Window->close();
}

void Game::Update()
{
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

		while (b_stopRenderer)
		{
			m_Window->clear(sf::Color::Black);
			m_Window->display();

			b_rendererStoped = true;
		}
	}
}

void Game::Events()
{
	sf::Event event;
	while (m_Window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			m_Window->close();

		m_Scene->Events(event);

	}

}

