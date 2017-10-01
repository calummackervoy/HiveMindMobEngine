#include "MapWorld.h"

MapWorld::MapWorld(string mapLocation, suint size) : Map(size) {
    
}

MapWorld::MapWorld(WorldParams config, suint size) : Map(size) {
	params = config;

	//figure out size big enough for the regions
	map->width = params.numRegions * 100;
	map->height = params.numRegions * 100;

	//generate region structure
	generateRegionStructure();

	//generate region geography
	generateRegionGeography();
}

MapWorld::~MapWorld() {

}

void MapWorld::generateRegionStructure() {
	//TODO: varying map structure
	tileSize = randInt(20, 100);
	//start at 0 & 0
	float x = 0.0f;
	float y = 0.0f;
	minX = x;
	maxX = x;
	minY = y;
	maxY = y;

	for (int i = 0; i < params.numRegions; i++) {
		regions[i] = Renderer::getTriangleFan(7, sf::Vector2f(x, y), tileSize, sf::Color::White);
		int direction = randInt(0, 5);

		//keep trying next tile space along in that direction until empty found
		bool found = false;
		while (!found) {
			switch (direction) {
			case 0:
				x = x - tileSize;
				y = y - tileSize;
				break;
			case 1:
				x = x - tileSize;
				y = y + tileSize;
				break;
			case 2:
				y = y + tileSize;
				break;
			case 3:
				x = x + tileSize;
				y = y + tileSize;
				break;
			case 4:
				x = x + tileSize;
				y = y - tileSize;
				break;
			case 5:
				y = y - tileSize;
				break;
			}

			//anyone in it?
			found = true;
			for (int j = 0; j < params.numRegions; j++) {
				if (positions[j].x == x &&
					positions[j].y == y) {
					found = false;
				}
			}
		}

		//update the min/max x/y if necessary
		if (x < minX) minX = x;
		else if (x > maxX) maxX = x;
		if (y < minY) minY = y;
		else if (y > maxY) maxY = y;
	}
}

void MapWorld::generateRegionGeography() {
	minX = minX / tileSize;
	maxX = maxX / tileSize;
	minY = minY / tileSize;
	maxY = maxY / tileSize;

	for (int i = 0; i < MAX_REGIONS; i++) {
		//figure out position in tiles (and store)
		suint x = positions[i].x / tileSize;
		suint y = positions[i].y / tileSize;

		//figure out where this is relatively
		suint disFromLeft = minX - x;
		suint disFromRight = maxX - x;
		suint disFromTop = maxY - y;
		suint disFromBottom = minY - y;

		//TODO: finish generation
		//land or sea?

		//choices
	}
}

Grid* MapWorld::readMap(string mapLocation) {
	return {};
}