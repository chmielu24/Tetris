#include "SceneGame.h"
#include "Game.h"

SceneGame::SceneGame()
	:SceneName("Game", m_Font, 30)
{
	m_Font.loadFromFile("Fonts/8bit.TTF");

	sf::FloatRect textRect = SceneName.getLocalBounds();

	SceneName.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);

	SceneName.setPosition(0, 0);

}

void SceneGame::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(SceneName);
}

void SceneGame::Update()
{
}

void SceneGame::Events()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
	{
		Game::Instance().LoadScene("menu");
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
	{
		Game::Instance().LoadScene("options");
	}
}
