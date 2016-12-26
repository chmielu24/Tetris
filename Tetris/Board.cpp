#include "Board.h"

#include <SFML/Graphics/Sprite.hpp>



Board::Board(int xBlockCount, int yBlocksCount, int size)
{
	xSize = xBlockCount;
	ySize = yBlocksCount;

	int startX = -320, startY = 0;

	startX -= xSize * size / 2;
	startY -= ySize * size / 2;


	img.loadFromFile("Images/background.png");
	Tex.loadFromImage(img, sf::IntRect(0, 0, img.getSize().x, img.getSize().y));
	


	m_Blocks = new sf::Sprite*[ySize];
	m_positions = new sf::Vector2f*[ySize];
	for (int i = 0; i < ySize; i++)
	{
		m_Blocks[i] = new sf::Sprite[xSize];
		m_positions[i] = new sf::Vector2f[xSize];

	}

	for(int y = 0 ; y < ySize; y++)
		for (int x = 0; x < xSize; x++)
		{
			m_Blocks[y][x].setTexture(Tex);
			m_Blocks[y][x].setScale(float(size) / Tex.getSize().x, float(size) / Tex.getSize().y);

			m_positions[y][x].x = startX + (size)* x;
			m_positions[y][x].y = startY + (size)* y;

			m_Blocks[y][x].setPosition(m_positions[y][x]);
		}
}


Board::~Board()
{
	for (int i = 0; i < ySize; i++)
	{
		delete []m_Blocks[i];
		delete[]m_positions[i];
	}

	delete []m_Blocks;
	delete[]m_positions;
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
