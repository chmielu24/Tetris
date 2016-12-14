#pragma once
#include "Scene.h"
#include <SFML\Graphics.hpp>

class SceneMenu : public Scene
{
public:
	SceneMenu();
	virtual ~SceneMenu() = default;

	// Inherited via Scene
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
	virtual void Update() override;
	virtual void Events() override;

protected:
	sf::Text SceneName;
	sf::Font m_Font;
};