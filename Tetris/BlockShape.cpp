#include "BlockShape.h"
#include "defines.h"

void BlockShape::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (int y = 0; y < SHAPE_SIZE; y++)
		for (int x = 0; x < SHAPE_SIZE; x++)
		{
			target.draw(m_Block[y][x]);
		}

}


void BlockShape::RotateLeft()
{
	for (int y = 0; y < SHAPE_SIZE; y++)
	{
		for (int x = y+1; x < SHAPE_SIZE; x++)
		{
			auto tmp = m_Block[y][x].getType();
			m_Block[y][x].setType(m_Block[x][y].getType());
			m_Block[x][y].setType(tmp);
		}
	}

	for (int y = 0; y < SHAPE_SIZE/2; y++)
	{
		for (int x = 0; x < SHAPE_SIZE; x++)
		{
			auto tmp = m_Block[y][x].getType();
			m_Block[y][x].setType(m_Block[4-y][x].getType());
			m_Block[4-y][x].setType(tmp);
		}
	}

}

void BlockShape::RotateRight()
{
	for (int y = 0; y < SHAPE_SIZE; y++)
	{
		for (int x = y+1; x < SHAPE_SIZE; x++)
		{
			auto tmp = m_Block[y][x].getType();
			m_Block[y][x].setType(m_Block[x][y].getType());
			m_Block[x][y].setType(tmp);
		}
	}

	for (int y = 0; y < SHAPE_SIZE; y++)
	{
		for (int x = 0; x < SHAPE_SIZE/2; x++)
		{
			auto tmp = m_Block[y][x].getType();
			m_Block[y][x].setType(m_Block[y][4-x].getType());
			m_Block[y][4-x].setType(tmp);
		}
	}

}

BlockShape::BlockShape(float xBoard, float yBoard, float s)
{
	setBoard(xBoard, yBoard, s);
}

void BlockShape::setBoard(float x, float y, float s)
{
	BlockSize = s;
	xBoard = x;
	yBoard = y;

	for (int y = 0; y < SHAPE_SIZE; y++)
		for (int x = 0; x < SHAPE_SIZE; x++)
		{
			m_Block[y][x].Initialize(x, y, s);
		}
}

void BlockShape::SetType(BlockType t[SHAPE_SIZE][SHAPE_SIZE])
{
	for (int y = 0; y < SHAPE_SIZE; y++)
		for (int x = 0; x < SHAPE_SIZE; x++)
			m_Block[y][x].setType(t[y][x]);
}

void BlockShape::SetType(BlockShape t)
{
	for (int y = 0; y < SHAPE_SIZE; y++)
		for (int x = 0; x < SHAPE_SIZE; x++)
			m_Block[y][x].setType(t.m_Block[y][x].getType());
}

void BlockShape::setPosition(float x1, float y1)
{
	m_boardPosition.x = x1;
	m_boardPosition.y = y1;

	m_position.x = xBoard + x1 * BlockSize;
	m_position.y = yBoard + y1 * BlockSize;

	for (int y = -2; y <= SHAPE_SIZE -3; y++)
		for (int x = -2; x <= SHAPE_SIZE -3; x++)
		{
			m_Block[y + 2][x + 2].setPosition(m_position.x + x * BlockSize, m_position.y + y * BlockSize);
		}
}

void BlockShape::setRealPosition(float x, float y)
{
	m_position.x = x;
	m_position.y = y;

	for (int y = -2; y <= SHAPE_SIZE -3; y++)
		for (int x = -2; x <= SHAPE_SIZE -3; x++)
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

	for (int y = -2; y <= SHAPE_SIZE -3; y++)
		for (int x = -2; x <= SHAPE_SIZE -3; x++)
		{
			m_Block[y + 2][x + 2].setPosition(m_position.x + x * BlockSize, m_position.y + y * BlockSize);
		}
}