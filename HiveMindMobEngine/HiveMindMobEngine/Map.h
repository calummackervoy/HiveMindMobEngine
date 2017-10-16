#pragma once
#include "ResourceManager.h"
#include "RendererConfig.h"
#include "FileHandler.h"
#include "Tile.h"
#include <string>
#include <math.h>

//Author: Calum Mackervoy
//Purpose: Base class for all types of map-management

using std::string;

//NOTE: map tiles are organised in 2D array like so: map[x][y]
class Map {
public:
	Map(const suint size);
	~Map();

	inline Tile* getTerrainAt(int x, int y) {
		//bounds checking
		if (x < 0 || x > size || y < 0 || y > size) return NULL;
		return map[x][y];
	};

	//setting a new map
	//void setMap(string mapLocation) { map = FileHandler::readMap(mapLocation); };

	//method to get which tile a given x,y co-ordinate is in
	sf::Vector2i convertToTile(const sf::Vector2f pos);

protected:
	//MapType mapType;
	Tile* map[MAX_MAP_SIZE][MAX_MAP_SIZE];
	suint size;
};