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
	return true;
}

void Events::Uninitialize()
{

}

void Events::On(std::string eventName, EventHandler handler)
{
	eventHandlers[eventName].push_back(handler);
}

CategoryHandlers::iterator find(CategoryHandlers::iterator _First, CategoryHandlers::iterator _Last, EventHandler& _Val)
{	// find first matching _Val
	_DEBUG_RANGE(_First, _Last);
	
	while (_First != _Last)
	{
		if (_First->target<EventHandler>() == _Val.target<EventHandler>())
			break;

		_First++;
	}

	return _First;
}

void Events::Off(std::string eventName, EventHandler handler)
{
	CategoryHandlers::const_iterator foundHandler = find(eventHandlers[eventName].begin(), eventHandlers[eventName].end(), handler);

	if (foundHandler != eventHandlers[eventName].cend())
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
