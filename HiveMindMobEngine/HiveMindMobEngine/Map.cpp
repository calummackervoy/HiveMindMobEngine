#include "Map.h"

Map::Map(Renderer* r, ResourceManager* rm, suint size) {
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
	mapCentre = sf::Vector2i(size * 0.5, size* 0.5);
	viewCentre = mapCentre;
	//mapCentre = screenToWorld(r->getWindow()->getView().getCenter());
	highlight = sf::Vector2i(0, 0);

	//initialise the static sprites for highlighting declared in Tile.h
	spriteHighlightHover = new GameSprite(r->getTexture("../../assets/sprites/ui/tile_highlight_yellow.png"));

	first = true;
}

Map::~Map() {
	delete[] map;

	//delete the static sprites declared in Tile.h
	delete spriteHighlightHover;
	spriteHighlightHover = NULL;
}
void Map::readMap(FileHandler* file, std::string mapLocation) {
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

			x = (i * TILE_SIZE) + TILE_SIZE * 0.5f;
			y = (j * TILE_SIZE) + TILE_SIZE * 0.5f;

			map[i][j]->setWorldPos(sf::Vector2f(x, y));
			//std::cout << "[READ MAP " << i << "]: (" << x << ", " << y << ")" << std::endl;
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
	mapCentre = sf::Vector2i(size * 0.5, size* 0.5);
	viewCentre = mapCentre;
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

sf::Vector2i Map::convertScreenToTile(const sf::RenderWindow* win, sf::Vector2i screenpos) {
	//convert mouse position to world
	screenpos = (sf::Vector2i)screenToWorld((sf::Vector2f)screenpos);

	//get it relative to the map's centrepoint
	sf::Vector2i temp = (sf::Vector2i)map[mapCentre.x][mapCentre.y]->getWorldPos();
	//off by half a tile error workaround
	screenpos = (temp - screenpos) + sf::Vector2i(TILE_SIZE * 0.5f, TILE_SIZE * 0.5f);

	//calculate how many tiles from centre you are
	sf::Vector2i tilesFromCentre = sf::Vector2i((screenpos.x / TILE_SIZE), (screenpos.y / TILE_SIZE));

	//fetch this tile using the centre
	sf::Vector2i result = mapCentre - tilesFromCentre;

	//off-by-one errors for negative values
	if (screenpos.x > 0) result.x -= 1;
	if (screenpos.y < 0) result.y += 1;

	return result;
}

void Map::draw(sf::RenderWindow* win) {
	//set view
	sf::View view = win->getView();
	//reverse project center
	sf::Vector2f centre = worldToScreen(map[viewCentre.x][viewCentre.y]->getWorldPos());
	view.setCenter(centre);
	win->setView(view);

	for (int i = 0; i < sizeAxis; i++) {
		for (int j = 0; j < sizeAxis; j++) {
			if (map[i][j] != NULL) {
				//draw with a highlight or not
				if(i == highlight.x && j == highlight.y) map[i][j]->draw(win, spriteHighlightHover);
				else map[i][j]->draw(win, NULL);
			}
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

void Map::highlightHover(sf::RenderWindow* win, sf::Vector2i mousepos) {
	highlight = convertScreenToTile(win, mousepos);
}