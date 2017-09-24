#pragma once
#include "Renderer.h"
#include "MouseKeyboard.h"

//Author: Calum Mackervoy
//Purpose: Handle input and respond to trigger appropriate action

class InputHandler {
public:
	InputHandler(Renderer* r, FileHandler* f, DeviceType type = MOUSE_KEYBOARD);
	~InputHandler();

	//input detection
	DeviceResponse respond();

private:
	Renderer* r;
	Device* device;
};