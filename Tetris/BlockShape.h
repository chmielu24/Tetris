#pragma once
#include "BlockType.h"
#include "BoardBlock.h"
#include <SFML\Graphics.hpp>

class BlockShape : public sf::Drawable
{
public:
	BlockShape() = default;
	~BlockShape();

	void setBoard(float xBoard, float yBoard, float s);
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

	void setPosition(float x, float y);
	void setRealPosition(float x, float y);
	const sf::Vector2f getPosition() { return m_boardPosition; }
	void move(float x, float y);

	const BlockType GetType(int x, int y) { return m_Block[y][x].getType(); }
	void SetType(int x, int y, BlockType type) { m_Block[y][x].setType(type); }
	void SetType(BlockType t[5][5]);
	void SetType(BlockShape t);

protected:
	BoardBlock m_Block[5][5];
	sf::Vector2f m_position;
	sf::Vector2f m_boardPosition;

	int xBoard;
	int yBoard;
	int BlockSize;
};