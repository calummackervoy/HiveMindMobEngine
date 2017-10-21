#pragma once
#include "ResourceManager.h"
#include "RendererConfig.h"
#include "FileHandler.h"
#include "Tile.h"
#include <string>

//Author: Calum Mackervoy
//Purpose: Base class for all types of map-management

using std::string;

//NOTE: map tiles are organised in 2D array like so: map[x][y]
class Map {
public:
	Map(ResourceManager* rm, suint size = 2);
	~Map();

	//reading in a map
	//files should have 1 int for size, then 2 ints per tile- one for terrain type and one for terrain graphic
	void readMap(FileHandler* file, string mapLocation);

	void resize(suint size); //resize the map
	void clear();

	//sf::Vector2f projectMouseCoords(int mx, int my, sf::RenderWindow *win);

	inline Tile* getTerrainAt(int x, int y) {
		//bounds checking
		if (x < 0 || x > size || y < 0 || y > size) return NULL;
		return map[x][y];
	};
	sf::Vector2f getMapCentre() { return mapCentre; };

	//setting a new map
	//void setMap(string mapLocation) { map = FileHandler::readMap(mapLocation); };

	//moving the screen view around
	void setMapCentre(sf::Vector2f centre) { mapCentre = centre; };
	void incremementMapCentre(bool x, bool y) {
		if (x) mapCentre.x++;
		if (y) mapCentre.y++;
	};
	void deccremementMapCentre(bool x, bool y) {
		if (x) mapCentre.x--;
		if (y) mapCentre.y--;
	};

	//method to get which tile a given x,y co-ordinate is in
	sf::Vector2i convertToTile(const sf::Vector2f pos);

	//function to draw the map and it's contents
	void draw(sf::RenderWindow* win);

protected:
	ResourceManager* rm;
	//MapType mapType;
	//NOTE: stored [columns][rows]
	Tile* map[MAX_MAP_SIZE][MAX_MAP_SIZE];
	//track the centre position of the current view on the map
	sf::Vector2f mapCentre;
	suint size; //storage of the total number of tiles in the map
	suint sizeAxis; //storage of the number of tiles on each axis
	//bool lighting;
	bool first; //for debugging- only print deets on first draw loop
};