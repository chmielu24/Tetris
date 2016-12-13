#pragma once
#include <vector>
#include <memory>
#include <SFML\Graphics.hpp>
#include "DrawUpdate.h"
#include "Time.h"

class Game
{
public:
	virtual ~Game();
	void Start();

	static Game& Instance()
	{
		static Game game;
		return game;
	}

protected:
	Game();
	void Update();
	void RendererThread();


	std::unique_ptr<sf::RenderWindow> m_Window;
	std::unique_ptr<sf::Thread> m_Thread;

	std::vector<DrawUpdate*> v_GameObjects;
	
	std::unique_ptr<Time> m_Time;

	int i_FPSMax;
};