#pragma once
#include "ISystem.h"
#include <unordered_map>
#include <string>

union SDL_Event;

class SDLInput :
	public ISystem
{
private:
	class Events* events;

	std::unordered_map<int, std::string> inputEventMapping;
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

