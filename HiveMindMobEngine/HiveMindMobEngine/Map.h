#pragma once
#include "RendererConfig.h"
#include "FileHandler.h"
#include "Terrain.h"
#include <string>

//Author: Calum Mackervoy
//Purpose: Base class for all types of map-management

using std::string;

//TODO: active map in game manager
enum MapType : uint8_t {
	MAP_WORLD,
	MAP_REGION,
	MAP_BATTLE
};

struct MapConfig {

};

class Map {
public:
	Map();
	~Map();

	inline Tile getTerrainAt(int x, int y) {
		return map.grid[x][y];
	};

	//setting a new map
	void setMap(string mapLocation) { map = FileHandler::readMap(mapLocation); };

protected:
	MapType mapType;
	Grid map;
};