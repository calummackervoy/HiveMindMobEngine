#include "Map.h"

Map::Map(suint size) {
	//mapType = MAP_WORLD;
	map = NULL;
	this->size = size;
}

Map::~Map() {
	delete map;
}