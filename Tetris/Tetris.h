#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\System\Vector2.hpp>
#include <random>
#include <memory>
#include <vector>
#include "DrawUpdate.h"
#include "BoardForm.h"
#include "BoardBlock.h"
#include "BlockShape.h"



class Tetris : public DrawUpdate
{
public:
	Tetris(int, int, int, int);
	virtual ~Tetris();

	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
	virtual void Update() override;

	void MoveX(float offsetX);
	void Rotate(int);
	void GoDown(bool);
	const int GetScore() { return i_Score; }

protected:
	void RespawnBlock();
	void CalculateYColision();
	bool SetBlockToBoard();
	void chceckBoard();
	void RandNextShape();
	void AddScore(int score);

	int xSize;
	int ySize;

	int xBoard;
	int yBoard;
	int BlockSize;

	float FallDownSpeed;
	float FallDownSpeedFast;

	bool b_goDown;
	bool b_GameOver;
	int i_fallBlockYColision;
	int Dificult;

	sf::Font m_Font;
	sf::Text m_Score;
	int i_Score;

	
	std::vector<std::vector<std::unique_ptr<BoardBlock>>> m_BoardBlock;

	BlockShape FallBlock;
	BlockShape NextBlock;

	std::vector<BlockShape> BlockShapeList;


	std::random_device r;
	std::default_random_engine e1;
	int sumTickets;
};

