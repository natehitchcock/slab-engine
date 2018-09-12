#pragma once

#include <vector>
#include <unordered_map>
#include <string>
#include "ISystem.h"

#define STRINGIFY(toStringify) #toStringify

class Application: public ISystem
{
private:
	std::vector<ISystem*> systems;

	std::unordered_map<std::string, ISystem*> systemRegistration;

	bool isRunning;

	static Application* instance;

	class Events* events;
public:
	// TODO: implement filesystem path management class
	Application(std::string applicationConfigPath);
	~Application();

	void Initialize();
	bool Update();
	void Uninitialize();

	bool GetIsRunning();
	void Quit();

	static Application* GetInstance()
	{
		return instance;
	}

	void RegisterSystem(std::string baseType, ISystem* systemInstance);
	ISystem* GetSystem(std::string baseType);
};

#define REGISTER_SYSTEM(baseType, instance) Application::GetInstance()->RegisterSystem(SystemType<baseType>::GetName(), instance);
#define GET_SYSTEM(baseType) (baseType*)Application::GetInstance()->GetSystem(SystemType<baseType>::GetName());
