#include "Events.h"
#include "Application.h"
#include <algorithm>

Events::Events()
{
	REGISTER_SYSTEM(Events, this);
}

Events::~Events()
{
}

void Events::Initialize()
{

}

bool Events::Update()
{
	// TODO: Examine potential for making threaded event handlers
	// TODO: Add Immediate vs time sliced events (ex coroutines or promises)
}

void Events::Uninitialize()
{

}

void Events::On(std::string eventName, EventHandler handler)
{
	eventHandlers[eventName].push_back(*handler);
}

void Events::Off(std::string eventName, EventHandler handler)
{
	CategoryHandlers::const_iterator foundHandler = std::find(eventHandlers[eventName].cbegin, eventHandlers[eventName].cend, handler);

	if (foundHandler != eventHandlers[eventName].cend)
	{
		eventHandlers[eventName].erase(foundHandler);
	}
}

void Events::Send(std::string eventName, void* data)
{
	CategoryHandlers categoryHandlers = eventHandlers[eventName];

	for (EventHandler& handler : categoryHandlers)
	{
		handler(data);
	}
}
