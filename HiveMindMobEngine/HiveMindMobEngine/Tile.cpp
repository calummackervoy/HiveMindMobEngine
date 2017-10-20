#include "Tile.h"

Tile::Tile(ResourceManager* rm, Terrain ter, TerrainGraphic floorTex) {
	this->rm = rm;
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

void Tile::draw(sf::RenderWindow* win) {
	//draw the terrain graphic
	win->draw(sf::Sprite(*rm->terrain[floorTex]));

	//TODO: draw everything else
}

void Tile::clear() {
	//set all occupants etc to NULL
	for (int i = 0; i < MAX_TILE_OCCUPANTS; i++) {
		//for each bucket, check the id of the sprite to see if it's allocated in RM
		//if it is, remove it..
		//NOTE: resource manager will ignore removal requests for sprites not assigned to it
		if (decor[i] != NULL) {
			rm->removeSprite(decor[i]->getIndex());
			decor[i] = NULL;
		}
		if (interactables[i] != NULL) {
			rm->removeSprite(interactables[i]->getIndex());
			interactables[i] = NULL;
		}
		if (occupants[i] != NULL) {
			rm->removeSprite(occupants[i]->getIndex());
			occupants[i] = NULL;
		}
	}

	//delete the roof tile
	delete roof;
	roof = NULL;
}