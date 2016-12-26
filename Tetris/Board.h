#pragma once
#include <SFML\Graphics.hpp>
#include "DrawUpdate.h"
#include <SFML\System\Vector2.hpp>

class Board : public DrawUpdate
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
	sf::Vector2f **m_positions;
	sf::Image img;
	sf::Texture Tex;
	
};

