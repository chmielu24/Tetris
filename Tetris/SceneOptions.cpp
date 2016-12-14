#include "SceneOptions.h"
#include "Game.h"

SceneOptions::SceneOptions()
	:SceneName("Options", m_Font, 30)
{
	m_Font.loadFromFile("Fonts/8bit.TTF");

	sf::FloatRect textRect = SceneName.getLocalBounds();

	SceneName.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);

	SceneName.setPosition(0, 0);

}

void SceneOptions::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(SceneName);
}

void SceneOptions::Update()
{
}

void SceneOptions::Events()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
	{
		Game::Instance().LoadScene("game");
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
	{
		Game::Instance().LoadScene("menu");
	}
}
