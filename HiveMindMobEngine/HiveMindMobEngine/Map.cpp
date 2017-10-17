#include "Map.h"

Map::Map(suint size) {
	//mapType = MAP_WORLD;
	//enforce maximum map size
	size = std::max((uint)size, MAX_MAP_SIZE);
	this->size = size * size;

	//initialise map to array of NULLs
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			map[j * size + i] = NULL;
		}
	}
}

Map::~Map() {
	delete[] map;
}

void Map::resize(suint size) {
	clear();
	this->size = size * size;
}

void Map::clear() {
	for (int i = 0; i < MAX_MAP_SIZE; i++) {
		for (int j = 0; j < MAX_MAP_SIZE; j++) {
			delete map[j * size + i];
			map[j * size + i] = NULL;
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

	//Reverse-projecting top-left corner to world space will give top-left node
	sf::Vector2f viewsize = view.getSize();
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
		if (row & 1)
		{
			//Odd row
			rowincx = 0;
			rowincy = 1;
			drawnodes = numCols;
		}
		else
		{
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
				map[celly * size + cellx]->draw(win);
			}
		}

		nodex = nodex + rowincx;
		nodey = nodey + rowincy;
	}
}