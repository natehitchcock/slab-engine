#pragma once

class ISystem
{
public:
	// TODO: Do I need a virtual dtor here for the inheritance heirarchy to be correctly destructed?

	// Used for connecting to other systems and
	//	for when grabbing something in the constructor isn't safe
	virtual void Initialize() = 0;
	
	// Returns true if the app should stop
	virtual bool Update() = 0;
	
	// Used to disconnect from other systems safely, before destruction
	virtual void Uninitialize() = 0;
private:
};

template<typename T>
struct SystemType
{
	static const char* GetName() { return "NONE";  };
};

#define ENABLE_SYSTEM_TYPE(A) template<> struct SystemType<A> { static const char* GetName() { return #A; } };
