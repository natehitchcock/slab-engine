#include "Application.h"

// TODO: read in config file and use that to add systems to application
#include "VulkanRenderer.h"

Application::Application(std::string applicationConfigPath)
	: isRunning(true)
{
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

	if (shouldContinue)
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
