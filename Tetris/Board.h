#pragma once
#include <SFML\Graphics.hpp>
#include "DrawUpdate.h"
#include <SFML\System\Vector2.hpp>
#include "BoardForm.h"
#include <vector>
#include "BoardBlock.h"
#include "BlockShape.h"

class Board : public DrawUpdate
{
public:
	Board(int, int,int );
	virtual ~Board();

	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
	virtual void Update() override;

	void MoveX(float offsetX);
	void GoDown(bool);

protected:
	void RespawnBlock();
	void CalculateYColision();
	bool SetBlockToBoard();
	void chceckBoard();

	int xSize;
	int ySize;

	int xBoard;
	int yBoard;
	int BlockSize;

	float FallDownSpeed;
	bool b_goDown;
	bool b_GameOver;
	
	BoardBlock **m_BoardBlock;

	int i_fallBlockYColision;
	BlockShape FallBlock;
	BlockShape NextBlock;

	std::vector<BlockShape> BlockShapeList;
};

