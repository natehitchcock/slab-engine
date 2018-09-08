#include "Application.h"

// TODO: read in config file and use that to add systems to application
#include "VulkanRenderer.h"

Application* Application::instance = nullptr;

Application::Application(std::string applicationConfigPath)
	: isRunning(true),
	systems(),
	systemRegistration()
{
	if (instance == nullptr)
	{
		instance = this;
	}
	else
	{
		//Log.Error("Attempt to create application when one already exists")
	}

	// Add systems in config order
	systems.push_back(new VulkanRenderer());
}

void Application::Initialize()
{
	for (ISystem* system : systems)
	{
		system->Initialize();
	}
}

bool Application::Update()
{
	bool shouldContinue = true;
	for (ISystem* system : systems)
	{
		shouldContinue = shouldContinue && system->Update();
	}

	if (!shouldContinue)
		isRunning = false;

	return isRunning;
}

void Application::Uninitialize()
{
	for (ISystem* system : systems)
	{
		system->Uninitialize();
	}
}

bool Application::GetIsRunning()
{
	return isRunning;
}

void Application::Quit()
{
	isRunning = false;
}

void Application::RegisterSystem(std::string baseType, ISystem* systemInstance)
{
	systemRegistration[baseType] = systemInstance;
}

ISystem* Application::GetSystem(std::string baseType)
{
	return systemRegistration[baseType];
}
