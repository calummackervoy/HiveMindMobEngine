#include "Physics.h"

Physics::Physics() {

}

Physics::~Physics() {

}

//interface detection with any BoundingBox
bool Physics::interfaceBoundingBox(sf::Vector2i pos, BoundingBox area) {
	float maxx = area.x + area.width;
	float maxy = area.y + area.height;

	if (pos.x <= maxx && pos.x >= area.x &&
		pos.y <= maxy && pos.y >= area.y) {
		return true;
	}
	return false;
}