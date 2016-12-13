#pragma once
#include <SFML\System\Clock.hpp>
#include <SFML\Graphics\Text.hpp>
#include <SFML\Graphics.hpp>
#include "DrawUpdate.h"


class Time final : public DrawUpdate
{
public:
	Time(bool showFPS, float x, float y);
	~Time() = default;


	virtual void Update() override;
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

	static const float& GetDeltaTime() noexcept
	{
		return deltaTime;
	}

	static const int& GetFPSCountPerSecond() noexcept
	{
		return FPSCountPerSecond;
	}
	
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
