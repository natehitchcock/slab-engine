#include "SDLInput.h"
#include "SDL.h"
#include "Application.h"
#include "Events.h"
#include <string>
#include <functional>
#include <iostream>

SDLInput::SDLInput()
{
}

SDLInput::~SDLInput()
{
}

void SDLInput::Initialize()
{
	events = GET_SYSTEM(Events);

	char* sdlEventNum = new char[10];
	SDL_uitoa(SDL_KEYUP, sdlEventNum, 10);

	std::string strKeyUpEventName = std::string("SDL_") + std::string(sdlEventNum);
	events->On(strKeyUpEventName, [=](void* data) {
		HandleKeyUp((SDL_Event*)data);
	});

	SDL_uitoa(SDL_KEYDOWN, sdlEventNum, 10);

	std::string strKeyDownEventName = std::string("SDL_") + std::string(sdlEventNum);
	events->On(strKeyDownEventName, [=](void* data) {
		HandleKeyDown((SDL_Event*)data);
	});
}

bool SDLInput::Update()
{
	return true;
}

void SDLInput::Uninitialize()
{

}

void SDLInput::HandleKeyUp(SDL_Event* sdlEvent)
{
	std::cout << "Got a key up!" << std::endl;
}

void SDLInput::HandleKeyDown(SDL_Event* sdlEvent)
{
	std::cout << "Got a key down!" << std::endl;
}
