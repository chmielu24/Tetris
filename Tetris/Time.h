#pragma once
#include <SFML\System\Clock.hpp>
#include <SFML\Graphics\Text.hpp>
#include <SFML\Graphics.hpp>
#include "DrawUpdate.h"


class Time : public DrawUpdate
{
public:
	Time(bool showFPS, float x, float y);


	virtual void Update() override;
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

	
private:
	static float deltaTime;
	static int FPSCountPerSecond;
	

	int iFPS;
	float fFPSClock;
	sf::Clock clock;

	bool bShowFPS;
	sf::Text FPSText;
	sf::Font font;


};
