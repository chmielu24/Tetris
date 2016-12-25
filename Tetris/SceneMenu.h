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
	virtual void Events(sf::Event&) override;

protected:
	sf::Text m_SceneOptions[3];
	sf::Text m_hiscores[10];
	int i_selectedOptions;
	sf::Font m_Font;
};