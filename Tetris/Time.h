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

	static const sf::Time& GetDeltaTime() noexcept
	{
		return deltaTime;
	}

	static const int& GetFPSCountPerSecond() noexcept
	{
		return FPSCountPerSecond;
	}
	
private:
	static sf::Time deltaTime;
	static int FPSCountPerSecond;
	

	sf::Time t_FPSClock;
	sf::Clock t_clock;

	bool b_ShowFPS;
	int i_FPS;
	sf::Text m_FPSText;
	sf::Font m_Font;


};
