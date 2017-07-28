#include "Map.h"

Map::Map() {
	//mapType = MAP_WORLD;
	map = NULL;
}

Map::~Map() {
	delete map;
}