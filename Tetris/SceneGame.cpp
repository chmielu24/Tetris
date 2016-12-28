#include "SceneGame.h"
#include "Game.h"

SceneGame::SceneGame()
	:SceneName("Game", m_Font, 30)
	,m_board(16,20,30)
{
	m_Font = AssetsLoader::GetAssets().Font1;

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
	m_board.Update();
}

void SceneGame::Events(sf::Event &event)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		Game::Instance().LoadScene("menu");
	}

	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Left)
		{
			m_board.MoveX(-1);
		}

		if (event.key.code == sf::Keyboard::Right)
		{
			m_board.MoveX(1);
		}

		if (event.key.code == sf::Keyboard::Down)
		{
			m_board.GoDown(true);
		}
	}

	if (event.type == sf::Event::KeyReleased)
	{
		if (event.key.code == sf::Keyboard::Down)
		{
			m_board.GoDown(false);
		}
	}
}
