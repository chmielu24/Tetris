#pragma once
#include <SFML\System\Vector2.hpp>
#include <SFML\Graphics.hpp>
class BoardForm
{
public:
	BoardForm();
	~BoardForm() = default; 

	void SetPosition(float x, float y, float, float,int);

	bool form[4][4];
	sf::Vector2f position;
	sf::Sprite sprite[4][4];
};