#pragma once
#include <SFML\Graphics.hpp>
#include "DrawUpdate.h"

class Board :public DrawUpdate
{
public:
	Board(int, int,int );
	virtual ~Board();

	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
	virtual void Update() override;

protected:
	int xSize;
	int ySize;
	
	sf::Sprite **m_Blocks;
	sf::Image img;
	sf::Texture Tex;
	// Inherited via DrawUpdate
	
};

