#include "BoardBlock.h"

void BoardBlock::Create(float x, float y, float size)
{
	f_BlockSize = size;
	m_sprite.setPosition(x,y);
	setType(BlockType::empty);
}

void BoardBlock::setType(BlockType t)
{
	m_type = t;

	switch (t)
	{
	case BlockType::empty: 	m_sprite.setTexture(AssetsLoader::GetAssets().EmptyBlock);
		break;
	case BlockType::red: m_sprite.setTexture(AssetsLoader::GetAssets().RedBlock);
		break;
	case BlockType::green: m_sprite.setTexture(AssetsLoader::GetAssets().GreenBlock);
		break;
	case BlockType::blue: m_sprite.setTexture(AssetsLoader::GetAssets().BlueBlock);
		break;
	default:
		break;
	}

	m_sprite.setScale(float(f_BlockSize) / m_sprite.getTexture()->getSize().x, float(f_BlockSize) / m_sprite.getTexture()->getSize().y);
}


void BoardBlock::setPosition(float x, float y)
{
	m_position.x = x;
	m_position.y = y;

	m_sprite.setPosition(m_position);
}

void BoardBlock::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	if(m_type != BlockType::none)
	target.draw(m_sprite);
}
