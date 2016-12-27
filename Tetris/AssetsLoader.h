#pragma once
#include <SFML\Graphics.hpp>


struct Assets 
{
	sf::Texture EmptyBlock;
	sf::Texture RedBlock;
	sf::Texture GreenBlock;
	sf::Texture BlueBlock;

	sf::Font Font1;
};

class AssetsLoader
{
public:
	
	~AssetsLoader() = default;

	const static Assets& GetAssets() 
	{
		static AssetsLoader loader;
		return  loader.assets;
	}

protected:
	AssetsLoader();
	void Load();
	static Assets assets;
};

