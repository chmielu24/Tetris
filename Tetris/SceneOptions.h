#pragma once

#include <SFML\Graphics.hpp>
#include "Scene.h"

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
	sf::Font m_Font;
	sf::Text m_Options[4];
	sf::Text m_OptionsVal[4];
	int i_selectedOptions;

private:
	void Set();
};