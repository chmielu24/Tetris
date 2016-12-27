#include "Board.h"

#include <SFML/Graphics/Sprite.hpp>
#include "Time.h"


Board::Board(int xBlockCount, int yBlocksCount, int size)
{
	xSize = xBlockCount;
	ySize = yBlocksCount;
	BlockSize = size;

	xBoard = -320;
	yBoard = 0;

	xBoard -= xSize * size / 2;
	yBoard -= ySize * size / 2;


	
	m_BoardBlock = new BoardBlock*[ySize];

	for (int i = 0; i < ySize; i++)
	{
		m_BoardBlock[i] = new BoardBlock[xSize];
	}

	for(int y = 0 ; y < ySize; y++)
		for(int x = 0; x < xSize; x++)
		{
			m_BoardBlock[y][x].Create(xBoard + (size)* x, yBoard + (size)* y, size);
		}


	RespawnBlock();
}


Board::~Board()
{
	for (int i = 0; i < ySize; i++)
	{
		delete []m_BoardBlock[i];
	}

	delete []m_BoardBlock;
}


void Board::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (int y = 0; y < ySize; y++)
		for (int x = 0; x < xSize; x++)
		{
			m_BoardBlock[y][x].draw(target, states);
		}
	

}


void Board::Update()
{

}

void Board::RespawnBlock()
{

}
