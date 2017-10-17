#pragma once
#include "Renderer.h"
#include "ResourceManager.h"
#include "Typedef.h"
#include "Terrain.h"
#include "GameSprite.h"
#include "Logger.h"

const suint TILE_SIZE = 64;
const suint MAX_TILE_OCCUPANTS = 4;

enum SpriteType {
	SPRITETYPE_OCCUPANT,
	SPRITETYPE_DECOR,
	SPRITETYPE_INTERACTABLE
};

class Tile
{
public:
	Tile(Terrain ter= FLAT_GROUND, TerrainGraphic floorTex = FLOOR_GRASS);
	~Tile();

	//function for drawing a tile(rendering)
	void draw(sf::RenderWindow* win, ResourceManager* rm);
	void clear();

	inline bool insertSprite(GameSprite* s, SpriteType type) {
		switch (type) {
		case SPRITETYPE_OCCUPANT:
			for (int i = 0; i < MAX_TILE_OCCUPANTS; i++) {
				if (occupants[i] == NULL) {
					occupants[i] = s;
					return true;
				}
			}
			return false;
		case SPRITETYPE_DECOR:
			for (int i = 0; i < MAX_TILE_OCCUPANTS; i++) {
				if (decor[i] == NULL) {
					decor[i] = s;
					return true;
				}
			}
			return false;
		case SPRITETYPE_INTERACTABLE:
			for (int i = 0; i < MAX_TILE_OCCUPANTS; i++) {
				if (interactables[i] == NULL) {
					interactables[i] = s;
					return true;
				}
			}
			return false;
		}
	};
	inline void removeSprite(suint i, SpriteType type) {
		switch (type) {
		case SPRITETYPE_OCCUPANT:
			//bounds checking
			if (i < 0 || i >= MAX_TILE_OCCUPANTS) return;
			occupants[i] = NULL;
			break;
		case SPRITETYPE_DECOR:
			//bounds checking
			if (i < 0 || i >= MAX_TILE_OCCUPANTS) return;
			decor[i] = NULL;
			break;
		case SPRITETYPE_INTERACTABLE:
			//bounds checking
			if (i < 0 || i >= MAX_TILE_OCCUPANTS) return;
			interactables[i] = NULL;
			break;
		}
	};

	//getters
	inline GameSprite* getOccupantAt(int i) {
		if (i < 0 || i > MAX_TILE_OCCUPANTS) {
			Logger::logError("Tile", "getSpriteAt out of bounds");
			return NULL;
		}
		return occupants[i];
	};
	inline GameSprite* getDecorAt(int i) {
		if (i < 0 || i > MAX_TILE_OCCUPANTS) {
			Logger::logError("Tile", "getSpriteAt out of bounds");
			return NULL;
		}
		return decor[i];
	};
	inline GameSprite* getInteractableAt(int i) {
		if (i < 0 || i > MAX_TILE_OCCUPANTS) {
			Logger::logError("Tile", "getSpriteAt out of bounds");
			return NULL;
		}
		return interactables[i];
	};
	//inline bool hasRoof() { if(roof == NULL) return true; else return false; };
	inline Tile* getRoof() { return roof; };
	inline Terrain getTerrain() { return terrain; };
	inline TerrainGraphic getFloorTex() { return floorTex; };
	//setters
	inline void setRoof(Tile* val) { delete roof; roof = val; };
	inline void setTerrain(Terrain val) { terrain = val; };
	inline void setFloorTex(TerrainGraphic val) { floorTex = val; };

protected:
	//list of decoration sprites/objects on the tile
	GameSprite* decor[MAX_TILE_OCCUPANTS];
	//list of interactive/item sprites/objects on the tile
	GameSprite* interactables[MAX_TILE_OCCUPANTS];
	//list of sprites inside of it
	GameSprite* occupants[MAX_TILE_OCCUPANTS];
	//if tile has a walkable roof
	Tile* roof;
	//terrain info
	Terrain terrain;
	TerrainGraphic floorTex;
};