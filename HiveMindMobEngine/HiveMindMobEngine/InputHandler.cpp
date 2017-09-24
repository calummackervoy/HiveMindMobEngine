#include "InputHandler.h"

InputHandler::InputHandler(Renderer* r, FileHandler* f, DeviceType type) {
	this->r = r;

	switch (type) {
	case MOUSE_KEYBOARD:
		device = new MouseKeyboard(f);
		break;
	}
}

InputHandler::~InputHandler() {
	delete device;
}

DeviceResponse InputHandler::respond() {
	sf::Event event;

	// while there are pending events...
	while (r->getWindow()->pollEvent(event)) {
		//offload the event onto the device
		return device->respond(event);
	}
}