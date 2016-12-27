#include "Time.h"
#include <SFML\Graphics.hpp>
#include "AssetsLoader.h"

int Time::FPSCountPerSecond = 0;
sf::Time Time::deltaTime = sf::Time::Zero;

Time::Time(bool showFPS, float x, float y) :
	b_ShowFPS(showFPS)
{
	m_Font = AssetsLoader::GetAssets().Font1;

	m_FPSText.setPosition(x, y);
	m_FPSText.setCharacterSize(20);
	m_FPSText.setFont(m_Font);
	
	i_FPS = 0;
	t_clock.restart();
}


void Time::Update()
{
	deltaTime = t_clock.restart();

	t_FPSClock += deltaTime;
	i_FPS++;

	if (t_FPSClock.asMilliseconds() >= 1000)
	{
		t_FPSClock -= sf::milliseconds(1000);
		FPSCountPerSecond = i_FPS;
		i_FPS = 0;

		m_FPSText.setString(std::to_string(FPSCountPerSecond));
	}
}


void Time::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if(b_ShowFPS)
	target.draw(m_FPSText, states);
}

