#pragma once
#include "Typedef.h"
#include "Terrain.h"
#include "GameSprite.h"
#include "Logger.h"

const suint TILE_SIZE = 20;
const suint MAX_TILE_OCCUPANTS = 4;

class Tile
{
public:
	Tile(Terrain ter= FLAT_GROUND, TerrainGraphic floorTex = FLOOR_DEFAULT);
	~Tile();

	//sprite occupancy of the tile
	inline bool insertOccupant(GameSprite* s) {
		for (int i = 0; i < MAX_TILE_OCCUPANTS; i++) {
			if (occupants[i] == NULL) {
				occupants[i] = s;
				return true;
			}
		}
		return false;
	};
	inline bool insertDecor(GameSprite* s) {
		for (int i = 0; i < MAX_TILE_OCCUPANTS; i++) {
			if (decor[i] == NULL) {
				decor[i] = s;
				return true;
			}
		}
		return false;
	};
	inline bool insertInteractable(GameSprite* s) {
		for (int i = 0; i < MAX_TILE_OCCUPANTS; i++) {
			if (interactables[i] == NULL) {
				interactables[i] = s;
				return true;
			}
		}
		return false;
	};
	inline void removeOccupant(int i) {
		//bounds checking
		if (i < 0 || i >= MAX_TILE_OCCUPANTS) return;
		occupants[i] = NULL;
	};
	inline void removeDecor(int i) {
		//bounds checking
		if (i < 0 || i >= MAX_TILE_OCCUPANTS) return;
		decor[i] = NULL;
	};
	inline void removeInteractable(int i) {
		//bounds checking
		if (i < 0 || i >= MAX_TILE_OCCUPANTS) return;
		interactables[i] = NULL;
	};
	void clear();

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