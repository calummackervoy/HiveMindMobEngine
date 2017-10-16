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

class Map {
public:
	Map(suint size);
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
	//method to get which tile a given x,y co-ordinate is in
	sf::Vector2i convertToTile(sf::Vector2f pos);

protected:
	//MapType mapType;
	Grid* map;
	suint size;
};