#pragma once
#include "Config.h"
#include "RendererConfig.h"
#include "FileHandler.h"
#include "Terrain.h"
#include "Grid.h"
#include <string>

//Author: Calum Mackervoy
//Purpose: Base class for all types of map-management

using std::string;

class Map {
public:
	Map();
	~Map();

	/*inline Tile getTerrainAt(int x, int y) {
		if (mapType == MAP_WORLD) {
			return ((WorldGrid*)(map))->grid[x][y];
		}
		else {

		}
	};*/

	//setting a new map
	//void setMap(string mapLocation) { map = FileHandler::readMap(mapLocation); };

protected:
	//MapType mapType;
	Grid* map;
};