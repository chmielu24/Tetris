#pragma once
#include <vector>
#include <memory>
#include <chrono>
#include <thread>
#include <SFML\Graphics.hpp>
#include "DrawUpdate.h"
#include "Time.h"
#include "Settegins.h"
#include "Scene.h"
#include "AssetsLoader.h"

class Game
{
public:
	virtual ~Game() = default;
	void Start();

	void LoadScene(std::string);
	void ExitGame();

	static Game& Instance()
	{
		static Game game;
		return game;
	}

protected:
	Game();
	void Update();
	void RendererThread();
	void Events();
	void Bind();

	std::unique_ptr<sf::RenderWindow> m_Window;
	std::unique_ptr<sf::Thread> m_Thread;

	std::vector<DrawUpdate*> v_GameObjects;
	
	std::unique_ptr<Time> m_Time;
	std::unique_ptr<Settegins> m_Settegins;

	std::unique_ptr<Scene> m_Scene;

	bool b_stopRenderer;
	bool b_rendererStoped;

	std::chrono::milliseconds timeDelay;
};