#include "Tile.h"

Tile::Tile(Terrain ter, TerrainGraphic floorTex) {
	terrain = ter;
	this->floorTex = floorTex;

	for (suint i = 0; i < MAX_TILE_OCCUPANTS; i++) {
		occupants[i] = NULL;
	}
	roof = NULL;
}

Tile::~Tile() {
	clear();
}

void Tile::clear() {
	//set all occupants to NULL
	for (suint i = 0; i < MAX_TILE_OCCUPANTS; i++) {
		occupants[i] = NULL;
	}

	//delete the roof tile
	delete roof;
	roof = NULL;
}