#pragma once
#include "Terrain.h"

enum TileType : uint8_t {
	SPECIFIC_TILE,
	REGION_LAND_TILE,
	REGION_WATER_TILE,
	REGION_SPACE_TILE
};

struct Tile {
	TileType type;
};

struct SpecificTile : Tile {
	TerrainGraphic terrainGraphic = DEFAULT;
	Terrain terrain = FLAT_GROUND;
	uint8_t level = 0;
	bool freeRunnable = false;
};

struct RegionTile : Tile {
	Climate climate = TEMPERATE_COLD;
	FeaturePresence mountains = NO_PRESENCE;
	FeaturePresence urban = LARGE_AREA;
	FeaturePresence rural = SPARSE;
	FeaturePresence woodland = SPARSE;
	FeaturePresence swamp = NO_PRESENCE;
	FeaturePresence water = NO_PRESENCE;
};

struct RegionWaterTile : Tile {
	FeaturePresence underwaterCity = NO_PRESENCE;
	FeaturePresence floatingCity = NO_PRESENCE;
	FeaturePresence coralReef = NO_PRESENCE;
};

struct RegionSpaceTile : Tile {
	//TODO much later down the line
};

typedef struct Grid {
	suint width = 0;
	suint height = 0;
};

typedef struct RegularGrid : Grid {
	Tile grid[MAX_WIDTH][MAX_HEIGHT];
};

typedef struct WorldGrid : Grid {
	RegionTile grid[MAX_WIDTH][MAX_HEIGHT];
};