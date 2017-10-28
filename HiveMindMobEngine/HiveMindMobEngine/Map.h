#pragma once
#include "ResourceManager.h"
#include "RendererConfig.h"
#include "FileHandler.h"
#include "Tile.h"

//Author: Calum Mackervoy
//Purpose: Base class for all types of map-management

//NOTE: map tiles are organised in 2D array like so: map[x][y]
class Map {
public:
	Map(Renderer* r, ResourceManager* rm, suint size = 2);
	~Map();

	//reading in a map
	//files should have 1 int for size, then 2 ints per tile- one for terrain type and one for terrain graphic
	void readMap(FileHandler* file, std::string mapLocation);
	//setting a new map
	//void setMap(string mapLocation) { map = FileHandler::readMap(mapLocation); };

	void resize(suint size); //resize the map
	void clear();

	//sf::Vector2f projectMouseCoords(int mx, int my, sf::RenderWindow *win);

	inline Tile* getTileAt(int x, int y) {
		//bounds checking
		if (x < 0 || x > size || y < 0 || y > size) return NULL;
		return map[x][y];
	};
	//inserting a sprite into a tile
	inline bool insertSprite(int x, int y, ResourceManager* rm, GameSprite* s, SpriteType type) {
		//bounds checking
		if (x < 0 || x > size || y < 0 || y > size) return NULL;
		return map[x][y]->insertSprite(rm, s, type);
	};

	sf::Vector2i getViewCentre() { return viewCentre; };
	//moving the screen view around
	void setViewCentre(sf::Vector2i centre) { viewCentre = centre; };
	void moveViewCentre(int x, int y) {
		if (x > 0) {
			if (viewCentre.x < sizeAxis - 1) {
				viewCentre.x += x;
			}
		}
		else {
			if (viewCentre.x > 0) {
				viewCentre.x += x;
			}
		}
		if (y > 0) {
			if (viewCentre.y < sizeAxis - 1) {
				viewCentre.y += y;
			}
		}
		else {
			if (viewCentre.y > 0) {
				viewCentre.y += y;
			}
		}
	};

	//method to get which tile a given x,y screen co-ordinate is in
	sf::Vector2i convertScreenToTile(const sf::RenderWindow* win, sf::Vector2i screenpos);

	//function to draw the map and it's contents
	void draw(sf::RenderWindow* win);
	//function to highlight a tile being hovered over
	void highlightHover(sf::RenderWindow* win, sf::Vector2i mousepos);

protected:
	ResourceManager* rm;
	GameSprite* spriteHighlightHover;
	//MapType mapType;
	//NOTE: stored [columns][rows]
	Tile* map[MAX_MAP_SIZE][MAX_MAP_SIZE];
	//track the centre position of the current view on the map
	sf::Vector2i viewCentre;
	//track the centre position of the map as a whole
	sf::Vector2i mapCentre;
	//track which tile is to be highlighted
	sf::Vector2i highlight;
	suint size; //storage of the total number of tiles in the map
	suint sizeAxis; //storage of the number of tiles on each axis
	//bool lighting;
	bool first; //for debugging- only print deets on first draw loop
};