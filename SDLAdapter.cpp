#include "SDLAdapter.h"
#include "SDL.h"
#include "Application.h"
#include "Events.h"

SDLAdapter::SDLAdapter()
{
	REGISTER_SYSTEM(SDLAdapter, this);
}

SDLAdapter::~SDLAdapter()
{
}

void SDLAdapter::Initialize()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	events = GET_SYSTEM(Events);
}

bool SDLAdapter::Update()
{
	SDL_Event e;

	// TODO: Limit this sdl event polling to < 5 ms
	// e.type is a uint, 4294967295 is max uint, so 10 digits is enough
	char* eventName = new char[11];
	while (SDL_PollEvent(&e))
	{
		SDL_uitoa(e.type, eventName, 10);

		std::string fullEventName = std::string("SDL_") + std::string(eventName);
		events->Send(fullEventName, (void*)&e);
	}
	delete eventName;

	return true;
}

void SDLAdapter::Uninitialize()
{
	SDL_Quit();
}
