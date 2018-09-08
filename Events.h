#pragma once
#include <unordered_map>
#include <functional>
#include <string>

#include "ISystem.h"

typedef void EventHandler(void*);
typedef std::list<EventHandler> CategoryHandlers;

class Events : public ISystem
{
private:
	std::unordered_map<std::string, CategoryHandlers> eventHandlers;

public:
	Events();
	~Events();

	void Initialize();
	bool Update();
	void Uninitialize();

	void On(std::string eventName, EventHandler handler);
	void Off(std::string eventName, EventHandler handler);

	void Send(std::string eventName, void* data);
};

ENABLE_SYSTEM_TYPE(Events);
