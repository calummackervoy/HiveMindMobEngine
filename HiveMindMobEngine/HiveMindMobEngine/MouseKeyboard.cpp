#include "MouseKeyboard.h"

MouseKeyboard::MouseKeyboard(sf::RenderWindow* win, FileHandler* f) : Device(f) {
	type = MOUSE_KEYBOARD;
	this->win = win;

	//read the key bindings from config file
	//TODO: pass the below via the main config file
	readBindings("../../assets/config/keybindings.txt");
}

MouseKeyboard::~MouseKeyboard() {
	delete keys;
}

DeviceResponse MouseKeyboard::respond(sf::Event event) {
	DeviceResponse res;

	//translate event to our enum
	DeviceKeyBinding key = translateEvent(event);

	//click pos if necessary
	if (key == CLICK_LEFT || key == CLICK_RIGHT) {
		res.click = true;
		res.clickPos = sf::Vector2i{ event.mouseButton.x, event.mouseButton.y };
	}
	else res.clickPos = (sf::Vector2i)win->mapPixelToCoords(sf::Mouse::getPosition(*win));
	//else res.clickPos = sf::Vector2i(event.mouseMove.x, event.mouseMove.y); 
	
	//lookup keypress in mapping to actions
	DeviceResponseCode code = DEVICE_RESPONSE_NONE;
	if (key < KEY_NULL) {
		code = (DeviceResponseCode)bindings[key];
	}

	//set this as response code
	res.responseCode = code;

	return res;
}

MouseKeyboardKeys MouseKeyboard::translateEvent(sf::Event &event) {
	if (event.type == sf::Event::MouseButtonPressed) {
		switch (event.mouseButton.button) {
		case sf::Mouse::Left:
			return CLICK_LEFT;
		case sf::Mouse::Right:
			return CLICK_RIGHT;
		}
	}
	else if (event.type == sf::Event::KeyPressed) {
		switch (event.key.code) {
		case sf::Keyboard::Escape:
			return KEY_ESCAPE;
		case sf::Keyboard::Up:
			return KEY_UP;
		case sf::Keyboard::Down:
			return KEY_DOWN;
		case sf::Keyboard::Left:
			return KEY_LEFT;
		case sf::Keyboard::Right:
			return KEY_RIGHT;
		}
	}
	else return KEY_NULL;
}