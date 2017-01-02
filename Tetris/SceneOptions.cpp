#include "SceneOptions.h"
#include "Game.h"
#include "defines.h"

SceneOptions::SceneOptions()
	:i_selectedOptions(0),
	m_Options
	{ { "Dificult", m_Font, 30 },
	{ "SizeX", m_Font, 30 },
	{ "SizeY", m_Font, 30 },
	{ "SAVE", m_Font, 30 } },
	m_OptionsVal
	{ { std::to_string(Settegins::Get().dificult), m_Font, 30 },
	{ std::to_string(Settegins::Get().BoardXSize), m_Font, 30 },
	{ std::to_string(Settegins::Get().BoardYSize), m_Font, 30 },
	{ "", m_Font, 30} }
{
	m_Font = AssetsLoader::GetAssets().Font1;
	sf::FloatRect textRect;

	for (int i = 0; i < 4; i++)
	{
		textRect = m_Options[i].getLocalBounds();
		m_Options[i].setOrigin(textRect.left + textRect.width / 2.0f,
			textRect.top + textRect.height / 2.0f);

		m_Options[i].setPosition(-320, -200 + i * 100);

		textRect = m_OptionsVal[i].getLocalBounds();
		m_OptionsVal[i].setOrigin(textRect.left + textRect.width / 2.0f,
			textRect.top + textRect.height / 2.0f);

		m_OptionsVal[i].setPosition(320, -200 + i * 100);
	}

	m_Options[3].setPosition(0, 200);


	sf::Color r = sf::Color::Red;
	m_Options[i_selectedOptions].setFillColor(r);
	m_OptionsVal[i_selectedOptions].setFillColor(r);

}

void SceneOptions::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for each (auto &var in m_Options)
	{
		target.draw(var);
	}

	for each (auto &var in m_OptionsVal)
	{
		target.draw(var);
	}
}

void SceneOptions::Set()
{
	m_OptionsVal[0].setString(std::to_string(Settegins::Get().dificult));
	m_OptionsVal[1].setString(std::to_string(Settegins::Get().BoardXSize));
	m_OptionsVal[2].setString(std::to_string(Settegins::Get().BoardYSize));
}

void SceneOptions::Update()
{

}

void SceneOptions::Events(sf::Event &event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Up)
		{
			i_selectedOptions--;

			if (i_selectedOptions < 0)
				i_selectedOptions = 0;
			if (i_selectedOptions > 3)
				i_selectedOptions = 3;

			sf::Color w = sf::Color::White;
			sf::Color r = sf::Color::Red;


			for each (auto &var in m_Options)
			{
				var.setFillColor(w);
			}

			for each (auto &var in m_OptionsVal)
			{
				var.setFillColor(w);
			}

			m_Options[i_selectedOptions].setFillColor(r);
			m_OptionsVal[i_selectedOptions].setFillColor(r);
		}
		else if (event.key.code == sf::Keyboard::Down)
		{
			i_selectedOptions++;

			if (i_selectedOptions < 0)
				i_selectedOptions = 0;
			if (i_selectedOptions > 3)
				i_selectedOptions = 3;

			sf::Color w = sf::Color::White;
			sf::Color r = sf::Color::Red;

			for each (auto &var in m_Options)
			{
				var.setFillColor(w);
			}

			for each (auto &var in m_OptionsVal)
			{
				var.setFillColor(w);
			}

			m_Options[i_selectedOptions].setFillColor(r);
			m_OptionsVal[i_selectedOptions].setFillColor(r);


		}
		else if (event.key.code == sf::Keyboard::Return)
		{
			if (i_selectedOptions == 0)
			{
				switch (Settegins::Get().dificult)
				{
				case 1: Settegins::Set().dificult = 2; break;
				case 2: Settegins::Set().dificult = 3; break;
				case 3: Settegins::Set().dificult = 1; break;

				default:
					break;
				}
			}
			else if (i_selectedOptions == 1)
			{
				Settegins::Set().BoardXSize++;
				if (Settegins::Get().BoardXSize > MAX_BOARD_SIZE_X)
					Settegins::Set().BoardXSize = MIN_BOARD_SIZE_X;

			} 
			else if (i_selectedOptions == 2)
			{
				Settegins::Set().BoardYSize++;
				if (Settegins::Get().BoardYSize > MAX_BOARD_SIZE_X)
					Settegins::Set().BoardYSize = MIN_BOARD_SIZE_X;
			}
			else if (i_selectedOptions == 3)
			{
				Game::Instance().SaveSettegins();
				Game::Instance().LoadScene("menu");
				return;
			}

			Set();

		}

	}
}
