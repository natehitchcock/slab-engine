#pragma once
#include "ISystem.h"

union SDL_Event;

class SDLInput :
	public ISystem
{
private:
	class Events* events;
public:
	SDLInput();
	~SDLInput();

	void Initialize();
	bool Update();
	void Uninitialize();

private:
	void HandleKeyUp(SDL_Event* sdlEvent);
	void HandleKeyDown(SDL_Event* sdlEvent);
};

