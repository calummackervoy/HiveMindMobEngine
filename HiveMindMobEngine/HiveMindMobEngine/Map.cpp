#include "Map.h"

Map::Map(const suint size) {
	//mapType = MAP_WORLD;
	//enforce maximum map size
	this->size = std::max((uint)size, MAX_MAP_SIZE);

	//initialise map to array of NULLs
	for (int i = 0; i < this->size; i++) {
		for (int j = 0; j < this->size; j++) {
			map[i][j] = NULL;
		}
	}
}

Map::~Map() {
	delete map;
}

sf::Vector2i Map::convertToTile(const sf::Vector2f pos) {
	return sf::Vector2i(floor(pos.x / TILE_SIZE), floor(pos.y / TILE_SIZE));
}