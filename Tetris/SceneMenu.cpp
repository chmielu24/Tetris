#include "SceneMenu.h"
#include "Game.h"
#include <string.h>

SceneMenu::SceneMenu()
	:m_SceneOptions
	{{"Start Game", m_Font, 30 },
	{"Options", m_Font, 30},
	{"Exit", m_Font, 30 }}
	,i_selectedOptions(0)
{

	m_Font.loadFromFile("Fonts/8bit.TTF");
	sf::FloatRect textRect;

	for (int i = 0; i < 3; i++)
	{
		textRect = m_SceneOptions[i].getLocalBounds();
		m_SceneOptions[i].setOrigin(textRect.left + textRect.width / 2.0f,
			textRect.top + textRect.height / 2.0f);

		m_SceneOptions[i].setPosition(-320, -100 + i * 100);
	}
	sf::Color r = sf::Color::Red;
	m_SceneOptions[i_selectedOptions].setFillColor(r);


	for (int i = 0; i < 10; i++)
	{
		m_hiscores[i].setFont(m_Font);
		m_hiscores[i].setCharacterSize(25);
		m_hiscores[i].setString(std::to_string(i+1) + " " + "aaaaaa");

		textRect = m_hiscores[i].getLocalBounds();
		m_hiscores[i].setOrigin(textRect.left + textRect.width / 2.0f,
			textRect.top + textRect.height / 2.0f);

		m_hiscores[i].setPosition(320, -250 + i * 50);
	}

}

void SceneMenu::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for each (auto &var in m_SceneOptions)
	{
		target.draw(var);
	}

	for each (auto &var in m_hiscores)
	{
		target.draw(var);
	}
}

void SceneMenu::Update()
{

}

void SceneMenu::Events(sf::Event &event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Up)
		{
			i_selectedOptions--;

			if (i_selectedOptions < 0)
				i_selectedOptions = 0;
			if (i_selectedOptions > 2)
				i_selectedOptions = 2;

			sf::Color w = sf::Color::White;
			sf::Color r = sf::Color::Red;


			for each (auto &var in m_SceneOptions)
			{
				var.setFillColor(w);
			}

			m_SceneOptions[i_selectedOptions].setFillColor(r);
		}
		else if (event.key.code == sf::Keyboard::Down)
			{
				i_selectedOptions++;

				if (i_selectedOptions < 0)
					i_selectedOptions = 0;
				if (i_selectedOptions > 2)
					i_selectedOptions = 2;

				sf::Color w = sf::Color::White;
				sf::Color r = sf::Color::Red;

				for each (auto &var in m_SceneOptions)
				{
					var.setFillColor(w);
				}

				m_SceneOptions[i_selectedOptions].setFillColor(r);

			}
			else if (event.key.code == sf::Keyboard::Return)
				{
					if (i_selectedOptions == 0)
					{
						Game::Instance().LoadScene("game");
					}
					if (i_selectedOptions == 1)
					{
						Game::Instance().LoadScene("options");
					}
					if (i_selectedOptions == 2)
					{
						Game::Instance().ExitGame();
					}
				}

	}
}
