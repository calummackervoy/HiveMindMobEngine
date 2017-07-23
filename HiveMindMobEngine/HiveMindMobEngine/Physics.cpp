#include "Physics.h"

Physics::Physics() {

}

Physics::~Physics() {

}

//interface detection with any BoundingBox
bool Physics::interfaceBoundingBox(sf::Vector2i pos, BoundingBox area) {
	float maxx = pos.x + area.width;
	float maxy = pos.y + area.height;

	if (pos.x <= maxx && pos.x >= area.x &&
		pos.y <= maxy && pos.y >= area.y) {
		return true;
	}
	return false;
}