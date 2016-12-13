#include "Settegins.h"
#include <iostream>


Settegins::Settegins(std::string fileName)
	:FileName(fileName)
{
	Load();
}


Settegins::~Settegins()
{
}

void Settegins::Load()
{
	data.MaxFPS = 60;
	data.ShowFPS = true;
	data.ResX = 1280;
	data.ResY = 720;
	data.FullScreen = false;
}

void Settegins::Save()
{
}	
