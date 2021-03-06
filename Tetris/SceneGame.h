#pragma once
#include <SFML\Graphics.hpp>
#include "Scene.h"
#include "Tetris.h"

class SceneGame : public Scene
{
public:
	SceneGame();
	virtual ~SceneGame() = default;

	// Inherited via Scene
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
	virtual void Update() override;
	virtual void Events(sf::Event&) override;

protected:

	Tetris m_tetris;
};