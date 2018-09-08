#include "Application.h"

int main(void)
{
	// TODO: parse config path from cli param
	// TODO: CLI param parser
	std::string configPath = "./";

	Application app(configPath);
	
	app.Initialize();

	while (app.GetIsRunning())
	{
		app.Update();
	}

	app.Uninitialize();

	return 0;
}
