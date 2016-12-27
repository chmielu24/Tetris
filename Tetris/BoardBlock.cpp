#include "BoardBlock.h"

void BoardBlock::Create(float x, float y, float size)
{
	BlockSize = size;
	sprite.setPosition(x,y);
	setType(BlockType::empty);
}

void BoardBlock::setType(BlockType t)
{
	type = t;

	switch (t)
	{
	case BlockType::empty: 	sprite.setTexture(AssetsLoader::GetAssets().EmptyBlock);
		break;
	case BlockType::red: sprite.setTexture(AssetsLoader::GetAssets().RedBlock);
		break;
	case BlockType::green: sprite.setTexture(AssetsLoader::GetAssets().GreenBlock);
		break;
	case BlockType::blue: sprite.setTexture(AssetsLoader::GetAssets().BlueBlock);
		break;
	default:
		break;
	}


	sprite.setScale(float(BlockSize) / sprite.getTexture()->getSize().x, float(BlockSize) / sprite.getTexture()->getSize().y);
}


void BoardBlock::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(sprite);
}
