#pragma once
#include "Map.h"

//Author: Calum Mackervoy
//Purpose: Map manager variation for battle map

class MapBattle : Map {
public:
	MapBattle(string mapLocation);
	//generate a map
	MapBattle(MapConfig config = {});
	~MapBattle();

private:
};