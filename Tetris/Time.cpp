#include "Time.h"
#include <SFML\Graphics.hpp>

int Time::FPSCountPerSecond = 0;
float Time::deltaTime = 0;

Time::Time(bool showFPS, float x, float y) :
	bShowFPS(showFPS)
{
	font.loadFromFile("Fonts/8bit.TTF");

	FPSText.setPosition(x, y);
	FPSText.setCharacterSize(20);
	FPSText.setFont(font);
	

	deltaTime = 0;
	FPSCountPerSecond = 0;
	iFPS = 0;
	fFPSClock = 0;
	clock.restart();
}

void Time::Update()
{
	deltaTime = clock.restart().asSeconds();

	fFPSClock += deltaTime;
	iFPS++;

	if (fFPSClock >= 1.0f)
	{
		FPSCountPerSecond = iFPS;
		iFPS = 0;
		fFPSClock -= 1.0f;

		FPSText.setString(std::to_string(FPSCountPerSecond));
	}
}

void Time::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if(bShowFPS)
	target.draw(FPSText, states);
}

