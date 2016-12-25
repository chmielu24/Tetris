#include "Board.h"

#include <SFML/Graphics/Sprite.hpp>



Board::Board(int xBlockCount, int yBlocksCount, int size)
{
	xSize = xBlockCount;
	ySize = yBlocksCount;

	int startX = -180, startY = 0;

	startX -= xSize * size / 2;
	startY -= ySize * size / 2;


	img.loadFromFile("Images/img1.png");
	Tex.loadFromImage(img, sf::IntRect(0, 0, img.getSize().x, img.getSize().y));
	


	m_Blocks = new sf::Sprite*[ySize];
	for (int i = 0; i < ySize; i++)
	{
		m_Blocks[i] = new sf::Sprite[xSize];
	}

	for(int y = 0 ; y < ySize; y++)
		for (int x = 0; x < xSize; x++)
		{
			m_Blocks[y][x].setTexture(Tex);
			m_Blocks[y][x].setPosition(startX + (size+1) * x, startY + (size+1) * y);
			m_Blocks[y][x].scale(0.1f, 0.1f);
		}

}


Board::~Board()
{
	for (int i = 0; i < ySize; i++)
	{
		delete []m_Blocks[i];
	}

	delete []m_Blocks;
}


void Board::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (int y = 0; y < ySize; y++)
		for (int x = 0; x < xSize; x++)
		{
			target.draw(m_Blocks[y][x]);
			
		}
}


void Board::Update()
{
}
