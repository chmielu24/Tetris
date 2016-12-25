#pragma once

#pragma once
#include "Scene.h"
#include <SFML\Graphics.hpp>

class SceneOptions : public Scene
{
public:
	SceneOptions();
	virtual ~SceneOptions() = default;

	// Inherited via Scene
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
	virtual void Update() override;
	virtual void Events(sf::Event&) override;

protected:
	sf::Text SceneName;
	sf::Font m_Font;
};