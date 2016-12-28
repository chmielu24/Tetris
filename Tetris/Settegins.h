#pragma once
#include "SetteginsData.h"
#include <string>

class Settegins
{
public:
	Settegins(std::string);
	virtual ~Settegins();

	void Load();
	void Save();


	static const SetteginsData &Get()
	{ return data; }

	static SetteginsData &Set()
	 { return data; }

protected:
	static SetteginsData data;
	std::string FileName;
	void SetDefault();
};

