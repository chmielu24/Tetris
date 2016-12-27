#pragma once
#include <SFML\Graphics.hpp>
#include "DrawUpdate.h"
#include <SFML\System\Vector2.hpp>
#include "BoardForm.h"
#include <vector>
#include "BoardBlock.h"

class Board : public DrawUpdate
{
public:
	Board(int, int,int );
	virtual ~Board();

	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
	virtual void Update() override;

protected:
	void RespawnBlock();

	int xSize;
	int ySize;
	int xBoard;
	int yBoard;
	int BlockSize;
	
	sf::Texture m_texBackground;
	BoardBlock **m_BoardBlock;

};

