#pragma once
#include <stdint.h>
#include <SFML\Graphics.hpp>
#include "Typedef.h"
#include "Config.h"
#include "FileHandler.h"

//Author: Calum Mackervoy
//Purpose: Base class for an input device/controller

using std::map;

//each device type supported has an entry here
enum DeviceType : uint8_t {
	DEVICE_NULL = 0,
	MOUSE_KEYBOARD = 1
};

class Device {
public:
	Device(FileHandler* f) { file = f; };//bindings = NULL; };
	~Device() { };//delete bindings; };

	inline DeviceType getType() { return type; };
	/*void addBinding(sf::Event, ResponseCode);
	void removeBinding(sf::Event);
	void removeBindingAt(int i);*/

	//main method to handle input/output: respond to an event
	//TODO: which devices does SFML support?
	virtual DeviceResponse respond(sf::Event event) = 0;

protected:
	FileHandler* file;
	DeviceType type;

	map<DeviceKeyBinding, int> bindings;

	//method for reading in the bindings
	virtual void readBindings(string configLocation);
};