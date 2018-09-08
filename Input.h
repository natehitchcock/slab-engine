#pragma once
#include "ISystem.h"
class Input :
	public ISystem
{
public:
	Input();
	~Input();

	void Initialize();
	bool Update();
	void Uninitialize();
};

