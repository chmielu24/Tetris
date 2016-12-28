#include "Tetris.h"

#include <SFML/Graphics/Sprite.hpp>
#include "Time.h"
#include "Game.h"
#include <fstream>
#include <iostream>

Tetris::Tetris(int xBlockCount, int yBlocksCount, int size)
	:b_GameOver(false),
	xSize(xBlockCount),
	ySize(yBlocksCount),
	BlockSize(size),
	FallDownSpeed(1),
	sumTickets(0),
	e1(r())
{
	std::ifstream File;
	File.open("shapes.ini");

	while (!File.eof())
	{
		BlockType t[5][5];
		int i;

		for (int y = 0; y < 5; y++)
			for (int x = 0; x < 5; x++)
			{
				File >> i;
				t[y][x] = (BlockType)i;
			}

		File >> i;
		BlockShape b;
		b.setBoard(xBoard, yBoard, BlockSize);
		b.SetType(t);
		b.setChance(i);

		BlockShapeList.push_back(b);
	}
	for each (auto var in BlockShapeList)
		sumTickets += var.getChance();


	xBoard = -320 - xSize * BlockSize / 2;
	yBoard = 0 - ySize * BlockSize / 2;
	
	m_BoardBlock = new BoardBlock*[ySize];

	for (int i = 0; i < ySize; i++)
	{
		m_BoardBlock[i] = new BoardBlock[xSize];
	}

	for(int y = 0 ; y < ySize; y++)
		for(int x = 0; x < xSize; x++)
		{
			m_BoardBlock[y][x].Initialize(xBoard + (size)* x, yBoard + (size)* y, size);
		}

	NextBlock.setBoard(xBoard, yBoard, BlockSize);
	FallBlock.setBoard(xBoard, yBoard, BlockSize);
	NextBlock.setRealPosition(320, -200);
	
	RandNextShape();
	RespawnBlock();
}


Tetris::~Tetris()
{
	for (int i = 0; i < ySize; i++)
	{
		delete [] m_BoardBlock[i];
	}

	delete [] m_BoardBlock;
}


void Tetris::RandNextShape()
{
	std::uniform_int_distribution<int> uniform_dist(0, sumTickets-1);

	int rand = uniform_dist(e1);

	for each (auto var in BlockShapeList)
	{
		if (var.getChance() > rand)
		{
			NextBlock.SetType(var);
			break;
		}

		rand -= var.getChance();
	}
}

void Tetris::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	for (int y = 0; y < ySize; y++)
		for (int x = 0; x < xSize; x++)
		{
			target.draw(m_BoardBlock[y][x]);
		}

	target.draw(FallBlock);

	target.draw(NextBlock);
}


void Tetris::Update()
{
	if (b_GameOver == false)
	{
		if (b_goDown)
			FallBlock.move(0, 15 * Time::GetDeltaTime().asSeconds());
		else
			FallBlock.move(0, FallDownSpeed * Time::GetDeltaTime().asSeconds());

		if (FallBlock.getPosition().y >= i_fallBlockYColision - 1)
		{
			if (SetBlockToBoard())
				RespawnBlock();
			else
				b_GameOver = true;
		}
	}
}

bool Tetris::SetBlockToBoard()
{
	for (int y = 0; y < 5; y++)
		for (int x = 0; x < 5; x++)
		{
			if (FallBlock.GetType(x, y) != BlockType::none)
			{
				int x1 = FallBlock.getPosition().x + x - 2;
				int y1 = FallBlock.getPosition().y + y - 2;

				//game over
				if (y1 < 0)
				{
					return false;
				}
				m_BoardBlock[y1][x1].setType(FallBlock.GetType(x, y));
			}
		}

	chceckBoard();

	return true;
}

void Tetris::chceckBoard()
{
	for (int y = 0; y < ySize; y++)
	{
		bool isGood = true;
		for (int x = 0; x < xSize; x++)
		{
			if (m_BoardBlock[y][x].getType() == BlockType::empty)
			{
				isGood = false;
				break;
			}
		}

		if (isGood)
		{
			for (int y1 = y; y1 > 0 ; y1--)
			{
				for (int x = 0; x < xSize; x++)
				{
					m_BoardBlock[y1][x].setType(m_BoardBlock[y1 - 1][x].getType());
				}
			}

			if(y>1)
			y--;
		}
	}
}

void Tetris::MoveX(float offset)
{
	bool can = true;

	for(int y = 0; y < 5; y++)
		for (int x = 0; x < 5; x++)
		{
			if (FallBlock.GetType(x, y) != BlockType::none)
			{
				int x1 = FallBlock.getPosition().x + offset + x - 2;
				int y1 = FallBlock.getPosition().y + y - 2;

				if (y1 < 0)
					continue;

				if (x1 < 0 || x1 > xSize)
					can = false;
				else
				if (m_BoardBlock[y1][x1].getType() != BlockType::empty)
					can = false;
				if (m_BoardBlock[y1+1][x1].getType() != BlockType::empty)
					can = false;
			}
		}

	if(can && !b_GameOver)
	FallBlock.move(offset,0);

	CalculateYColision();
}

void Tetris::GoDown(bool b)
{
	b_goDown = b;
}


void Tetris::RespawnBlock()
{
	FallBlock.setPosition(xSize / 2, -3.5);

	for(int y=0;y<5;y++)
		for (int x = 0; x < 5; x++)
		{
			FallBlock.SetType(x, y, NextBlock.GetType(x, y));
		}

	CalculateYColision();

	RandNextShape();
}

void Tetris::CalculateYColision()
{
	i_fallBlockYColision = ySize +1;

	for (int y = 0; y < 5; y++)
		for (int x = 0; x < 5; x++)
		{
			if (FallBlock.GetType(x, y) != BlockType::none)
			{
				int x1 = FallBlock.getPosition().x + x - 2;
				int y1 = FallBlock.getPosition().y + y - 2;

				if (y1 < 0)
					y1 = 0;

				for (int i = y1; i < ySize; i++)
				{
					if (m_BoardBlock[i][x1].getType() != BlockType::empty)
					{
						if (i - y + 2 < i_fallBlockYColision)
							i_fallBlockYColision = i - y + 2;
					}
				}

				if (ySize - y + 2 < i_fallBlockYColision)
					i_fallBlockYColision = ySize - y + 2;
			}
		}
}


void Tetris::Rotate(int i)
{
	BlockShape b;
	b.setBoard(xBoard, yBoard, BlockSize);
	b.SetType(FallBlock);
	b.setPosition(FallBlock.getPosition().x, FallBlock.getPosition().y);

	if (i > 0)
	{
		b.RotateRight();
	}
	else
	{
		b.RotateLeft();
	}

	bool collision = false;
	for (int y = 0; y < 5; y++)
		for (int x = 0; x < 5; x++)
		{
			if (b.GetType(x, y) != BlockType::none)
			{
				int x1 = b.getPosition().x + x - 2;
				int y1 = b.getPosition().y + y - 2;

				if (x1 < 0 || x1 > xSize || y1 > ySize)
					collision = true;
				else 
					if (y1 > 0)
					{
						if (m_BoardBlock[y1][x1].getType() != BlockType::empty)
							collision = true;
					}

			}
		}

	if (!collision)
	{
		FallBlock.SetType(b);
		CalculateYColision();
	}
}