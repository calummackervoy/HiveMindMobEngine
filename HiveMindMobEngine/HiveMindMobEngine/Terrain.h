#pragma once
#include "Typedef.h"

const uint8_t MAX_WIDTH = 1000;
const uint8_t MAX_HEIGHT = 1000;

enum Terrain : uint8_t {
	OPEN,
	PART_COV,
	FULL_COV
};

//TODO: children with data for holding things useful to RegionMaps, BattleMaps and WorldMaps
struct Tile {
	Terrain terrain = OPEN;
};

typedef struct Grid {
	suint width = 0;
	suint height = 0;
	Tile grid[MAX_WIDTH][MAX_HEIGHT];
};