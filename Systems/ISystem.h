#pragma once

class ISystem
{
public:
	
	// Used for connecting to other systems and
	//	for when grabbing something in the constructor isn't safe
	virtual void Initialize() = 0;
	
	virtual void Update() = 0;
	
	// Used to disconnect from other systems safely, before destruction
	virtual void Uninitialize() = 0;
private:
};
