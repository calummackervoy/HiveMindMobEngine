#include "Tile.h"

Tile::Tile(ResourceManager* rm, Terrain ter, TerrainGraphic floorTex) {
	this->rm = rm;
	terrain = ter;
	this->floorTex = floorTex;
	this->worldpos = sf::Vector2f(0.0f, 0.0f);

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
	sf::Sprite drawme = sf::Sprite(*rm->terrain[floorTex]);
	drawme.setPosition(worldToScreen(worldpos));
	win->draw(drawme);

	//draw everything else
	for (int i = 0; i < MAX_TILE_OCCUPANTS; i++) {
		if (decor[i] != NULL) {
			drawme = *decor[i];
			drawme.setPosition(worldToScreen(decor[i]->getWorldPosition()));
			win->draw(drawme);
		}
	}
	for (int i = 0; i < MAX_TILE_OCCUPANTS; i++) {
		if (interactables[i] != NULL) {
			drawme = *interactables[i];
			drawme.setPosition(worldToScreen(interactables[i]->getWorldPosition()));
			win->draw(drawme);
		}
	}
	for (int i = 0; i < MAX_TILE_OCCUPANTS; i++) {
		if (occupants[i] != NULL) {
			//drawme = *occupants[i];
			drawme = sf::Sprite(*occupants[i]);
			drawme.setPosition(worldToScreen(occupants[i]->getWorldPosition()));
			win->draw(drawme);
		}
	}
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

void Tile::tieSpriteToBottom(GameSprite* s) {
	s->setOrigin(0.0f, s->getLocalBounds().top + s->getLocalBounds().height);
	//NOTE: the extra on each axis is to get around an off-by-one error on which tile it is drawn to
	//for the x axis and the y offset is to put it in the centre of the tile
	s->setWorldPosition(worldpos.x + TILE_SIZE, worldpos.y + (TILE_SIZE * 0.5f));
}