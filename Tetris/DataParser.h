#pragma once
#include <string>
#include <fstream>
#include <map>

enum class ReadWrite
{
	Read,
	Write
};

class DataParser
{
public:
	DataParser(std::string, ReadWrite);
	virtual ~DataParser();

	void Close();

	const bool isGood();

	int GetInt(std::string name);
	bool Getbool(std::string name);
	float GetFloat(std::string name);

	void SetInt(std::string name, int val);
	void Setbool(std::string name, bool val);
	void SetFloat(std::string name, float val);


protected:
	std::string FileName;
	std::fstream File;
	ReadWrite Flag;
	std::map<std::string, std::string> values;
	bool loaded;
};