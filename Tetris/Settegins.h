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


	const SetteginsData &Get()
	{ return data; }

	 SetteginsData &Set()
	 { return data; }

protected:
	SetteginsData data;
	std::string FileName;
	void SetDefault();
};

