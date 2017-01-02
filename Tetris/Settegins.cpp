#include <fstream>
#include "Settegins.h"
#include "DataParser.h"

SetteginsData Settegins::data;

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
	DataParser parser(FileName, ReadWrite::Read);

	if (parser.isGood())
	{
		try
		{
			data.MaxFPS = parser.GetInt("maxfps");
			data.ShowFPS = parser.Getbool("showfps");
			data.ResX = parser.GetInt("resx");
			data.ResY = parser.GetInt("resy");
			data.FullScreen = parser.Getbool("fullscreen");
			data.BoardXSize = parser.GetInt("boardxsize");
			data.BoardYSize = parser.GetInt("boardysize");
			data.FallSpeed = parser.GetFloat("fallspeed");
			data.dificult = parser.GetInt("dificult");
		}
		catch (std::exception e)
		{
			SetDefault();
			Save();
		}
	}
	else
	{
		SetDefault();
		Save();
	}

}

void Settegins::Save()
{

	DataParser parser(FileName, ReadWrite::Write);

	parser.SetInt("maxfps", data.MaxFPS);
	parser.Setbool("showfps", data.ShowFPS);
	parser.SetInt("resx", data.ResX);
	parser.SetInt("resy", data.ResY);
	parser.Setbool("fullscreen", data.FullScreen);
	parser.SetInt("boardxsize", data.BoardXSize);
	parser.SetInt("boardysize", data.BoardYSize);
	parser.SetFloat("fallspeed", data.FallSpeed);
	parser.SetInt("dificult", data.dificult);

	parser.Close();

}

void Settegins::SetDefault()
{
	data.MaxFPS = 60;
	data.ShowFPS = true;
	data.ResX = 1280;
	data.ResY = 720;
	data.FullScreen = false;
	data.BoardXSize = 14;
	data.BoardYSize = 18;
	data.FallSpeed = 1.0f;
	data.dificult = 1;
}
