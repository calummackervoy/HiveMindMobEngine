#include "Map.h"

Map::Map(suint size) {
	//mapType = MAP_WORLD;
	map = NULL;
	this->size = size;
}

Map::~Map() {
	delete map;
}

sf::Vector2i Map::convertToTile(sf::Vector2f pos) {
	return sf::Vector2i(floor(pos.x / TILE_SIZE), floor(pos.y / TILE_SIZE));
}