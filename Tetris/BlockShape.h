#pragma once
#include <SFML\Graphics.hpp>
#include "BlockType.h"
#include "BoardBlock.h"
#include "defines.h"

class BlockShape : public sf::Drawable
{
public:
	BlockShape() = default;
	BlockShape(float xBoard, float yBoard, float s);
	~BlockShape() = default;
	void setBoard(float xBoard, float yBoard, float s);
	
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

	void setPosition(float x, float y);
	void setRealPosition(float x, float y);
	const sf::Vector2f getPosition() { return m_boardPosition; }
	void move(float x, float y);

	void RotateLeft();
	void RotateRight();

	const BlockType GetType(int x, int y) { return m_Block[y][x].getType(); }
	void SetType(int x, int y, BlockType type) { m_Block[y][x].setType(type); }
	void SetType(BlockType t[SHAPE_SIZE][SHAPE_SIZE]);
	void SetType(BlockShape t);

	void setChance(int i) { chance = i; }
	const int getChance() { return chance; }

protected:
	BoardBlock m_Block[SHAPE_SIZE][SHAPE_SIZE];
	sf::Vector2f m_position;
	sf::Vector2f m_boardPosition;

	int xBoard;
	int yBoard;
	int BlockSize;
	int chance;
};