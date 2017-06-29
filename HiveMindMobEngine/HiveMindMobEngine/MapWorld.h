#pragma once
#include "Renderer.h"
#include "Map.h"
#include "rand.h"

//Author: Calum Mackervoy
//Purpose: Map manager variation for world map

//TODO: replace all const ints with uint8_t where necessary
const suint MAX_REGIONS = 32;

class MapWorld : Map {
public:
	MapWorld(string mapLocation);
	//generate a map
	MapWorld(WorldParams config = {});
	~MapWorld();

	//returns the actual region pointer
	inline sf::VertexArray* getRegionAt(int i) {
		return regions[i];
	};

	//returns a copy to be given to renderer and deleted when no longer required
	inline sf::VertexArray* copyRegionAt(int i) {
		sf::VertexArray* reg = new sf::VertexArray(*regions[i]);
		return reg;
	};

private:
	WorldParams params;
	suint minX, minY, maxX, maxY;
	sf::VertexArray* regions[MAX_REGIONS];
	sf::Vector2f positions[MAX_REGIONS];
	sf::Vector2i tilePositions[MAX_REGIONS];
	RegionTile regionTiles[MAX_REGIONS];
	suint tileSize;

	//TODO: replace with planet generation
	void generateRegionStructure();
	void generateRegionGeography();
};