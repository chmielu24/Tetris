#pragma once


struct SetteginsData
{
	SetteginsData()
	{
		ShowFPS = false;
		MaxFPS = 60;
		ResX = 1280;
		ResY = 720;
		FullScreen = false;
	}


	bool ShowFPS;
	int MaxFPS;
	int ResX;
	int ResY;
	bool FullScreen;
};