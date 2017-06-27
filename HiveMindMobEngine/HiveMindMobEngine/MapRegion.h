#pragma once
#include "Map.h"

//Author: Calum Mackervoy
//Purpose: Map manager variation for region map

class MapRegion : Map {
public:
	MapRegion(string mapLocation);
	//generate a map
	MapRegion(MapConfig config = {});
	~MapRegion();

private:
};