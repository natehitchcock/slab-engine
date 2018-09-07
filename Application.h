#pragma once

#include <vector>
#include <string>
#include "ISystem.h"

class Application: public ISystem
{
private:
	std::vector<ISystem*> systems;

	bool isRunning;
public:
	// TODO: implement filesystem path management class
	Application(std::string applicationConfigPath);
	void Initialize();
	bool Update();
	void Uninitialize();

	bool GetIsRunning();
	void Quit();
};
