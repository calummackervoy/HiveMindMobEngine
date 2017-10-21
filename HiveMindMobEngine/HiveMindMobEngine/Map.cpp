#include "Map.h"

Map::Map(ResourceManager* rm, suint size) {
	//mapType = MAP_WORLD;
	this->rm = rm;
	//enforce maximum map size
	size = std::max((uint)size, MAX_MAP_SIZE);
	sizeAxis = size;
	this->size = size * size;

	//initialise map to array of NULLs
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			map[i][j] = NULL;
		}
	}

	//mapCentre by default the middle of the map
	mapCentre = sf::Vector2f((float)size * 0.5, (float)size* 0.5);

	first = true;
}

Map::~Map() {
	delete[] map;
}
void Map::readMap(FileHandler* file, string mapLocation) {
	//open stream
	file->openStream(mapLocation, true);

	//read in the map size
	suint size = (suint)file->getNextInt();
	//resize if need be
	size = std::max((uint)size, MAX_MAP_SIZE);
	if (size != this->sizeAxis) resize(size);

	Terrain terType;
	TerrainGraphic graphic;

	float x;
	float y;

	//read in each tile until map is complete
	for (int i = 0; i < sizeAxis; i++) {
		for (int j = 0; j < sizeAxis; j++) {
			terType = (Terrain)file->getNextInt();
			graphic = (TerrainGraphic)file->getNextInt();
			map[i][j] = new Tile(rm, terType, graphic);

			x = i * TILE_SIZE;
			y = j * TILE_SIZE;

			map[i][j]->setWorldPos(sf::Vector2f(x, y));
			std::cout << "[READ MAP " << i << "]: (" << x << ", " << y << ")" << std::endl;
		}
	}

	//close stream
	file->closeStream();
}


void Map::resize(suint size) {
	clear();
	if (size < 2) size = 2; //bounds checking
	sizeAxis = size;
	this->size = size * size;
	
	//update mapCentre to middle of the new map
	mapCentre = sf::Vector2f((float)size * 0.5, (float)size* 0.5);
}

void Map::clear() {
	for (int i = 0; i < MAX_MAP_SIZE; i++) {
		for (int j = 0; j < MAX_MAP_SIZE; j++) {
			if (map[j * sizeAxis + i] != NULL) {
				delete map[j * sizeAxis + i];
				map[i][j] = NULL;
			}
		}
	}
}

sf::Vector2i Map::convertToTile(const sf::Vector2f pos) {
	return sf::Vector2i(pos.x / TILE_SIZE, pos.y / TILE_SIZE);
}

void Map::draw(sf::RenderWindow* win) {
	//set view
	sf::View view = win->getView();
	//reverse project center
	sf::Vector2f centre = worldToScreen(mapCentre);
	view.setCenter(centre);
	win->setView(view);

	for (int i = 0; i < sizeAxis; i++) {
		for (int j = 0; j < sizeAxis; j++) {
			if (map[i][j] != NULL) map[i][j]->draw(win);
		}
	}

	//TODO: this code was an attempt to draw just the tiles that may be on screen (inefficient to draw all as above)
	//Reverse-projecting top-left corner to world space will give top-left node
	/*sf::Vector2f viewsize = view.getSize();
	sf::Vector2f topleft = screenToWorld(sf::Vector2f(centre.x - viewsize.x * 0.5f,
		centre.y - viewsize.y * 0.5f));
	int sx = (int)(topleft.x / (float)TILE_SIZE);
	int sy = (int)(topleft.y / (float)TILE_SIZE);

	//Move start location up and left two nodes to get a little padding
	sx -= 2;

	//Calculate how many nodes across to draw
	//A node's total width on-screen is calculated as 4*nodesize
	int numCols = (int)viewsize.x / (TILE_SIZE * 4) + 4; // Pad out the end by drawing 4 extra nodes

	//draw a certain number of rows from this point below the view (padding)
	//NOTE: intentionally not covering everything that may be tall enough to be on screen- so that really tall
	//things are culled
	int numRows = ((int)viewsize.y / (TILE_SIZE * 2)) * 2;

	//Drawing
	//We begin at some starting node and proceed across the row. At each step, we increment x and decrement y
	//to move to the next node. When a row is done, we move to the next row. This is done by:
	//If the current row is "even", then we move to the next row by incrementing x. If the current row is odd, we
	//move to the next row by incrementing y instead.
	//On even rows, we draw num_nodes+1 nodes, else we draw num_nodes nodes.
	int rowincx = 1, rowincy = 0;
	int drawnodes = numCols + 1;

	int nodex = sx, nodey = sy;
	for (int row = 0; row < numRows; row++) {
		if (row & 1) {
			//Odd row
			rowincx = 0;
			rowincy = 1;
			drawnodes = numCols;
		}
		else {
			rowincx = 1;
			rowincy = 0;
			drawnodes = numCols + 1;
		}

		for (int node = 0; node < numCols; node++) {
			// Calculate cell coords
			int cellx = nodex + node;
			int celly = nodey - node;
			if (cellx >= 0 && cellx < size
				&& celly >= 0 && celly < size) {

				//draw the tile
				if (map[cellx][celly] != NULL) {
					map[cellx][celly]->draw(win);

					if (first) {
						std::cout << "[DRAW MAP " << cellx << ", " << celly << "]: (" << map[cellx][celly]->getWorldPos().x << ", " << map[cellx][celly]->getWorldPos().y << ")" << std::endl;
					}
				}
			}
		}

		nodex = nodex + rowincx;
		nodey = nodey + rowincy;
	}
	first = false;*/
}