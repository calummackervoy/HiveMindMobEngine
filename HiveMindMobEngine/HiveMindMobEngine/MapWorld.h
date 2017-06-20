#pragma once
#include "Map.h"

//Author: Calum Mackervoy
//Purpose: Map manager variation for world map

class MapWorld : Map {
public:
	MapWorld(string mapLocation) : Map();
	//generate a map
	MapWorld(MapConfig config = {}) : Map();
	~MapWorld();

private:
};