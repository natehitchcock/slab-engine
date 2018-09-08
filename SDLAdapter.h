#pragma once
#include "ISystem.h"
class SDLAdapter :
	public ISystem
{
private:
	// Other system references
	Events* events = nullptr;
public:
	SDLAdapter();
	~SDLAdapter();

	void Initialize();
	bool Update();
	void Uninitialize();
};

ENABLE_SYSTEM_TYPE(SDLAdapter);
