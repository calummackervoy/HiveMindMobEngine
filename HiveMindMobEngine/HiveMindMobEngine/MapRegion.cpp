#include "MapRegion.h"

/*MapRegion::MapRegion(ResourceManager* rm, string mapLocation, suint size) : Map(size) {
	this->rm = rm;
	DEBUG_MODE = true;
	map = new Grid;

	suint halfTile = TILE_SIZE * 0.5;

	//TODO: read the map in from a file

	int max = std::min(MAX_MAP_SIZE, size);

	//initialise a map to width & height (& rest NULL)
	for (int i = 0; i < max; i++) {
		for (int j = 0; j < max; j++) {
			//because it's a region map we will use Specific Tiles
			map->grid[i][j] = new SpecificTile;

			//set position accroding to index
			//cx, cy centre of square co-ords
			float cx = (TILE_SIZE * size);// *0.5);
			float cy = (TILE_SIZE * size);// *0.5);

			//X_FACTOR used to counter weird error, TILE_SIZE halved to be centre
			float x = 0.0f;
			//TODO: additional here is to deal with offset of corner of screen not being corner of map
			x += ((TILE_SIZE * 2) * (i + 1)); //+ (halfTile);
			float y = 0.0f;
			y += ((TILE_SIZE * 2) * (j + 1));// +(halfTile);

			//translate to the origin of (cx,cy)
			x = x - cx;
			y = y - cy;

			//rotate it on the map
			x = x*cos(7.0f) - y*sin(10.0f);
			//x = x*cos(160.0f) - y*sin(160.0f);
			y = x*sin(7.0f) + y*cos(10.0f);
			//y = x*sin(160.0f) + y*cos(160.0f);

			//translate back
			x = x + cx;
			y = y + cy;

			((SpecificTile*)(map->grid[i][j]))->x = x;
			((SpecificTile*)(map->grid[i][j]))->y = y;

			cout << "[" << i << ", " << j << "]: " << "<" << x << ", " << y << ">" << std::endl;
				
			//generate a point to indicate the position for testing
			if (DEBUG_MODE) {
				Element* e = new Element;
				e->elemType = CIRCLE_SHAPE;
				e->model = new sf::CircleShape(10.0f);
				((sf::CircleShape*)(e->model))->setOrigin(5.0f, 5.0f);
				((sf::CircleShape*)(e->model))->setPosition(TILE_SIZE, TILE_SIZE); //offset
				//((sf::CircleShape*)(e->model))->setPosition(x, y); //no offset
				//((sf::CircleShape*)(e->model))->rotate(MAP_ROTATION);
				((sf::CircleShape*)(e->model))->move((float)x, (float)y);
				((sf::CircleShape*)(e->model))->setFillColor(sf::Color::White);
				rm->addSceneElem(e);
			}
		}
	}

	//set remaining slots to NULL to mark the end of the grid
	if (size < MAX_MAP_SIZE) {
		for (int i = size; i < MAX_MAP_SIZE; i++) {
			for (int j = size; j < MAX_MAP_SIZE; j++) {
				map->grid[i][j] = NULL;
			}
		}
	}
}

MapRegion::MapRegion(ResourceManager* rm, MapConfig config) : Map(config.size) {
	this->rm = rm;
	DEBUG_MODE = true;
}

MapRegion::~MapRegion() {

}

Grid* MapRegion::readMap(string mapLocation) {
	return{};
}*/