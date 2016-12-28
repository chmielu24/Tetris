#pragma once
#include <SFML\Graphics.hpp>
#include "DrawUpdate.h"
#include <SFML\System\Vector2.hpp>
#include "BoardForm.h"
#include <vector>
#include "BoardBlock.h"
#include "BlockShape.h"
#include <random>


class Tetris : public DrawUpdate
{
public:
	Tetris(int, int,int );
	virtual ~Tetris();

	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
	virtual void Update() override;

	void MoveX(float offsetX);
	void Rotate(int);
	void GoDown(bool);

protected:
	void RespawnBlock();
	void CalculateYColision();
	bool SetBlockToBoard();
	void chceckBoard();
	void RandNextShape();

	int xSize;
	int ySize;

	int xBoard;
	int yBoard;
	int BlockSize;

	float FallDownSpeed;
	bool b_goDown;
	bool b_GameOver;
	int i_fallBlockYColision;

	
	BoardBlock **m_BoardBlock;

	BlockShape FallBlock;
	BlockShape NextBlock;

	std::vector<BlockShape> BlockShapeList;


	std::random_device r;
	std::default_random_engine e1;
	int sumTickets;
};

