#pragma once
#include "RenderConfig.h"
#include "FileHandler.h"
#include <string>

//Author: Calum Mackervoy
//Purpose: Manages active map (both region and battle)

using std::string;

enum ActiveMap : uint8_t {
	MAP_WORLD,
	MAP_REGION,
	MAP_BATTLE
};

class Map {
public:
	Map(string mapLocation);
	~Map();

	inline Terrain getTerrainAt(int x, int y) {
		return map[x][y];
	};

	//setting a new map
	void setMap(string mapLocation) { map = FileHandler::readMap(mapLocation); };
	void setActiveMap(ActiveMap type) { activeMap = type; };

private:
	ActiveMap activeMap;
	Map map;
};