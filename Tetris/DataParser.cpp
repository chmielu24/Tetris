#include "DataParser.h"
#include <algorithm>
#include <utility>

DataParser::DataParser(std::string fileName, ReadWrite flag)
	:FileName(fileName),
	loaded(false)
{
	if (flag == ReadWrite::Read)
	{
		File.open(FileName, std::fstream::in);

		std::string str;
		while (std::getline(File, str))
		{
			try
			{
				std::string key = str.substr(0, str.find('='));
				std::string value = str.substr(str.find('=')+1, str.length());

				key.erase(remove(key.begin(), key.end(), ' '), key.end());
				value.erase(remove(value.begin(), value.end(), ' '), value.end());

				values.insert(std::pair<std::string, std::string>(key, value));
			}
			catch (std::exception)
			{

			}
		}

		loaded = true;

		File.close();
	}
	else if (flag == ReadWrite::Write)
	{
		File.open(FileName, std::fstream::trunc | std::fstream::out);
		
	}

	Flag = flag;

}

DataParser::~DataParser()
{
	if (File.is_open())
		File.close();
}

void DataParser::Close()
{
	File.close();
}

const bool DataParser::isGood()
{
	return File.good() || loaded;
}

int DataParser::GetInt(std::string name)
{
	return std::stoi(values[name]);
}

bool DataParser::Getbool(std::string name)
{
	if (values[name] == "true")
		return true;
	else
		return false;
}

void DataParser::SetInt(std::string name, int val)
{
	if (File.is_open() && Flag == ReadWrite::Write)
	{
		File << name << "=" << val << "\n";
	}
}

void DataParser::Setbool(std::string name, bool val)
{
	if (File.is_open() && Flag == ReadWrite::Write)
	{
		if(val)
			File << name << "=" << "true" << "\n";
		else
			File << name << "=" << "false" << "\n";
	}
}


