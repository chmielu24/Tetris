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
		BoardXSize = 14;
		BoardYSize = 18;
	}

	~SetteginsData() = default;


	bool ShowFPS;
	int MaxFPS;
	int ResX;
	int ResY;
	bool FullScreen;
	int BoardXSize;
	int BoardYSize;
};