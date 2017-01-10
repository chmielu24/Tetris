#include "BoardBlock.h"

BoardBlock::BoardBlock(float xPos, float yPos, float BlockSize)
{
	Initialize(xPos, yPos, BlockSize);
}

void BoardBlock::Initialize(float x, float y, float size)
{
	f_BlockSize = size;
	m_sprite.setPosition(x,y);
	setType(BlockType::empty);
}

void BoardBlock::setType(BlockType t)
{
	m_type = t;

	switch (m_type)
	{
	case BlockType::empty: 	m_sprite.setTexture(AssetsLoader::GetAssets().EmptyBlock);
		break;
	case BlockType::red: m_sprite.setTexture(AssetsLoader::GetAssets().RedBlock);
		break;
	case BlockType::green: m_sprite.setTexture(AssetsLoader::GetAssets().GreenBlock);
		break;
	case BlockType::blue: m_sprite.setTexture(AssetsLoader::GetAssets().BlueBlock);
		break;
	case BlockType::dark: m_sprite.setTexture(AssetsLoader::GetAssets().DarkBlock);
		break;
	case BlockType::lightblue: m_sprite.setTexture(AssetsLoader::GetAssets().LightBlueBlock);
		break;
	case BlockType::orange: m_sprite.setTexture(AssetsLoader::GetAssets().OrangeBlock);
		break;
	case BlockType::purple: m_sprite.setTexture(AssetsLoader::GetAssets().PurpleBlock);
		break;
	case BlockType::yellow: m_sprite.setTexture(AssetsLoader::GetAssets().YellowBlock);
		break;
	default: m_sprite.setTexture(AssetsLoader::GetAssets().RedBlock);
		break;
	}

	if(m_type != BlockType::none)
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
