#pragma once
#include "Device.h"

//Author: Calum Mackervoy
//Purpose: Models the mouse/keyboard default device

class MouseKeyboard : public Device {
public:
	MouseKeyboard(sf::RenderWindow* win,FileHandler* f);
	~MouseKeyboard();

	DeviceResponse respond(sf::Event event) override;

	//TODO: better way to do this?
	//method to translate SFML event code into device key
	MouseKeyboardKeys translateEvent(sf::Event &event);

private:
	sf::RenderWindow* win;
	DeviceKeyBinding* keys;
};