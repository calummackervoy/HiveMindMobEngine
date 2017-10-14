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
	Tile();
	~Tile();

	//sprite occupancy of the tile
	bool insertSprite(GameSprite* s);
	void removeSprite(GameSprite* s);
	void clear();

	//getters
	inline GameSprite* getSpriteAt(int i) {
		if (i < 0 || i > MAX_TILE_OCCUPANTS) {
			Logger::logError("Tile", "getSpriteAt out of bounds");
			return NULL;
		}
		return occupants[i];
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
	//list of sprites inside of it
	GameSprite* occupants[MAX_TILE_OCCUPANTS];
	//if tile has a walkable roof
	Tile* roof;
	//terrain info
	Terrain terrain;
	TerrainGraphic floorTex;
};