#pragma once
#include <SFML\System\Vector2.hpp>
#include <SFML\Graphics.hpp>
#include "BlockType.h"
#include "AssetsLoader.h"

class BoardBlock : sf::Drawable
{
public:
	BoardBlock() = default;
	~BoardBlock() = default;

	void Create(float, float, float);



	void setType(BlockType);
	const BlockType getType() { return type; }

	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;


protected:
	sf::Sprite sprite;
	sf::Vector2f m_position;
	BlockType type;
	float BlockSize;
};