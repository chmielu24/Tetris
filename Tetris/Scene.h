#pragma once
#include "DrawUpdate.h"

class Scene : public DrawUpdate
{
public:
	Scene() = default;
	virtual ~Scene() = default;

	virtual void Events() = 0;
};