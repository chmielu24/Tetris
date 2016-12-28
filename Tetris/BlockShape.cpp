#include "BlockShape.h"

void BlockShape::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (int y = 0; y < 5; y++)
		for (int x = 0; x < 5; x++)
		{
			target.draw(m_Block[y][x]);
		}

}

BlockShape::~BlockShape()
{
	
}


void BlockShape::setBoard(float x, float y, float s)
{
	BlockSize = s;
	xBoard = x;
	yBoard = y;

	for (int y = 0; y < 5; y++)
		for (int x = 0; x < 5; x++)
		{
			m_Block[y][x].Create(x, y, s);
		}
}

void BlockShape::SetType(BlockType t[5][5])
{
	for (int y = 0; y < 5; y++)
		for (int x = 0; x < 5; x++)
			m_Block[y][x].setType(t[y][x]);
}

void BlockShape::SetType(BlockShape t)
{
	for (int y = 0; y < 5; y++)
		for (int x = 0; x < 5; x++)
			m_Block[y][x].setType(t.m_Block[y][x].getType());
}

void BlockShape::setPosition(float x1, float y1)
{
	m_boardPosition.x = x1;
	m_boardPosition.y = y1;

	m_position.x = xBoard + x1 * BlockSize;
	m_position.y = yBoard + y1 * BlockSize;

	for (int y = -2; y <= 2; y++)
		for (int x = -2; x <= 2; x++)
		{
			m_Block[y + 2][x + 2].setPosition(m_position.x + x * BlockSize, m_position.y + y * BlockSize);
		}
}

void BlockShape::setRealPosition(float x, float y)
{
	m_position.x = x;
	m_position.y = y;

	for (int y = -2; y <= 2; y++)
		for (int x = -2; x <= 2; x++)
		{
			m_Block[y + 2][x + 2].setPosition(m_position.x + x * BlockSize, m_position.y + y * BlockSize);
		}
}

void BlockShape::BlockShape::move(float x1, float y1)
{
	m_boardPosition.x += x1;
	m_boardPosition.y += y1;

	m_position.x += (x1 * BlockSize);
	m_position.y += (y1 * BlockSize);

	for (int y = -2; y <= 2; y++)
		for (int x = -2; x <= 2; x++)
		{
			m_Block[y + 2][x + 2].setPosition(m_position.x + x * BlockSize, m_position.y + y * BlockSize);
		}
}