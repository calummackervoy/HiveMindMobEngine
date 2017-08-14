#pragma once
#include "Typedef.h"
#include "Logger.h"

//Author: Calum Mackervoy
//Purpose: Basic camera functionality (just manages a bounding box which defines the view)
//TODO: there can be no rotation but zoom?

const int SHIFT_AMOUNT = 50;

class Camera {
public:
	//TODO: parameterise y of the position?
	Camera(sint globalWidth, sint globalHeight, sint width, sint height, sint x = 0);
	~Camera();

	//functions for shifting the camera up, down, left & right
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();

protected:
	sint globalWidth, globalHeight;
	sint width;
	sint height;
	//position of the top-left point
	sint x;
	sint y;
};