#pragma once
#include "MapRegion.h"

//Author: Calum Mackervoy
//Purpose: Map manager variation for region map

class MapRegion : Map {
public:
	MapRegion(string mapLocation) : Map();
	//generate a map
	MapRegion(MapConfig config = {}) : Map();
	~MapRegion();

private:
};