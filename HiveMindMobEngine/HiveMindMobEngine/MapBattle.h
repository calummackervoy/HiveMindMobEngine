#pragma once
#include "Map.h"

//Author: Calum Mackervoy
//Purpose: Map manager variation for battle map

class MapBattle : Map {
public:
	MapBattle(string mapLocation) : Map();
	//generate a map
	MapBattle(MapConfig config = {}) : Map();
	~MapBattle();

private:
};