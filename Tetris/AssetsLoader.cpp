#include "AssetsLoader.h"
Assets AssetsLoader::assets;


AssetsLoader::AssetsLoader()
{
	Load();
}

void AssetsLoader::Load()
{
	assets.Font1.loadFromFile("Fonts/8bit.TTF");
	assets.EmptyBlock.loadFromFile("Images/background.png");
	assets.RedBlock.loadFromFile("Images/red.png");
	assets.GreenBlock.loadFromFile("Images/green.png");
	assets.BlueBlock.loadFromFile("Images/blue.png");
	assets.DarkBlock.loadFromFile("Images/dark.png");
	assets.LightBlueBlock.loadFromFile("Images/lightblue.png");
	assets.OrangeBlock.loadFromFile("Images/orange.png");
	assets.PurpleBlock.loadFromFile("Images/purple.png");
	assets.YellowBlock.loadFromFile("Images/yellow.png");
}
