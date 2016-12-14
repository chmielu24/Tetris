#include "SceneMenu.h"
#include "Game.h"

SceneMenu::SceneMenu()
	:SceneName("Menu", m_Font, 30)
{
	m_Font.loadFromFile("Fonts/8bit.TTF");

	sf::FloatRect textRect = SceneName.getLocalBounds();

	SceneName.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);

	SceneName.setPosition(0,0);

}

void SceneMenu::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(SceneName);
}

void SceneMenu::Update()
{
}

void SceneMenu::Events()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
	{
		Game::Instance().LoadScene("game");
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
	{
		Game::Instance().LoadScene("options");
	}
}
