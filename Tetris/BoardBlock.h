#pragma once
#include <SFML\System\Vector2.hpp>
#include <SFML\Graphics.hpp>
#include "BlockType.h"
#include "AssetsLoader.h"

class BoardBlock :public sf::Drawable
{
public:
	BoardBlock() = default;
	~BoardBlock() = default;

	void Create(float, float, float);


	void setType(BlockType);
	const BlockType getType() { return m_type; }

	void setPosition(float, float);
	const sf::Vector2f getPosition() { return m_position; }

	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;


protected:
	sf::Sprite m_sprite;
	sf::Vector2f m_position;
	BlockType m_type;
	float f_BlockSize;
};