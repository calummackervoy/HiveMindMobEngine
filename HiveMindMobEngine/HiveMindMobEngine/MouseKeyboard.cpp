#include "MouseKeyboard.h"

MouseKeyboard::MouseKeyboard() : Device() {
	type = MOUSE_KEYBOARD;

	//read the key bindings from config file
	//TODO: pass the below via the main config file
	FileHandler::readBindings(bindings, "../../assets/config/keybindings.txt");
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
		res.clickPos = sf::Vector2i{ event.mouseButton.x, event.mouseButton.y };
	}
	
	//lookup keypress in mapping to actions
	DeviceResponseCode code = DEVICE_RESPONSE_NONE;
	if (key < KEY_NULL) {
		cout << "something got clicked/pressed" << std::endl;
		code = (DeviceResponseCode)bindings[key];
		cout << "code = " << code << ", " << "bindings[key] = " << (int)bindings[key] << std::endl;

		std::map<DeviceKeyBinding, int>::iterator iter;

		for (iter = bindings.begin(); iter != bindings.end(); ++iter) {
			cout << "key " << (int)iter->first << " binds to " << (int)iter->second << std::endl;
		}
	}
	if (code != DEVICE_RESPONSE_NONE) cout << "code was " << (int)code << std::endl;

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
		}
	}
	else return KEY_NULL;
}