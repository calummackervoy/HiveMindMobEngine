#pragma once
#include "Map.h"

//Author: Calum Mackervoy
//Purpose: Map manager variation for world map

class MapWorld : Map {
public:
	MapWorld(string mapLocation);
	//generate a map
	MapWorld(MapConfig config = {});
	~MapWorld();

private:
};