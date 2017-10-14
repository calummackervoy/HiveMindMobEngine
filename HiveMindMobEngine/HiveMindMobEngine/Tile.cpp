#include "Tile.h"

Tile::Tile(Terrain ter, TerrainGraphic floorTex) {
	terrain = ter;
	this->floorTex = floorTex;

	for (suint i = 0; i < MAX_TILE_OCCUPANTS; i++) {
		occupants[i] = NULL;
		decor[i] = NULL;
		interactables[i] = NULL;
	}
	roof = NULL;
}

Tile::~Tile() {
	clear();
}

void Tile::clear() {
	//set all occupants etc to NULL
	for (suint i = 0; i < MAX_TILE_OCCUPANTS; i++) {
		decor[i] = NULL;
		interactables[i] = NULL;
		occupants[i] = NULL;
	}

	//delete the roof tile
	delete roof;
	roof = NULL;
}