#include "SceneGame.h"
#include "Game.h"

SceneGame::SceneGame()
	:SceneName("Game", m_Font, 30)
	,m_board(12,18,30)
{
	m_Font.loadFromFile("Fonts/8bit.TTF");

	sf::FloatRect textRect = SceneName.getLocalBounds();

	SceneName.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);

	SceneName.setPosition(0, 0);
}

void SceneGame::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(m_board);
}

void SceneGame::Update()
{
	
}

void SceneGame::Events(sf::Event &event)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		Game::Instance().LoadScene("menu");
	}
}
