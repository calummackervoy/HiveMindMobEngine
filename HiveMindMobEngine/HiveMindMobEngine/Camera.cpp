#include "Camera.h"

Camera::Camera(sint globalWidth, sint globalHeight, sint width, sint height, sint x) {
	this->globalWidth = globalWidth;
	this->globalHeight = globalHeight;
	this->width = width;
	this->height = height;
	this->x = x;
	this->y = height;
}

Camera::~Camera() {

}

void Camera::moveLeft() {
	if ((x - SHIFT_AMOUNT) < 0) return; //bounds check
	x -= SHIFT_AMOUNT;
}

void Camera::moveRight() {
	if ((x + SHIFT_AMOUNT) > globalWidth) return; //bounds check
	x += SHIFT_AMOUNT;
}

void Camera::moveUp() {
	if ((y + SHIFT_AMOUNT) > globalHeight) return; //bounds check
	y += SHIFT_AMOUNT;
}

void Camera::moveDown() {
	if ((y - SHIFT_AMOUNT) < 0) return; //bounds check
	y -= SHIFT_AMOUNT;
}