#pragma once
#include <SFML\Graphics.hpp>
#include "Typedef.h"
#include "Freerun.h"

const uint8_t MAX_WIDTH = 1000;
const uint8_t MAX_HEIGHT = 1000;
const uint8_t NUM_TERRAIN_TYPES = 8;

enum Terrain : uint8_t {
	FLAT_GROUND,
	SLIGHT_INCLINE,
	DRASTIC_INCLINE,
	WALL,
	DOORWAY,
	WINDOW,
	PROP,
	INTERACTIVE
};

enum TerrainGraphic : uint8_t {
	DEFAULT = 0
};

const sf::Color terrainColours[NUM_TERRAIN_TYPES] = {

};

struct Tile {
	TerrainGraphic terrainGraphic = DEFAULT;
	Terrain terrain = FLAT_GROUND;
	uint8_t level = 0;
	bool freeRunnable = false;
};

enum Climate : uint8_t {
	ARCTIC,
	TUNDRA,
	TEMPERATE_COLD,
	TEMPERATE_WARM,
	PLAINS,
	TROPICAL,
	ARID,
	DESERT
};

enum FeaturePresence : uint8_t {
	EVERYWHERE,
	ABUNDANT,
	LARGE_AREA,
	SPARSE,
	SMALL_AREA,
	SINGULAR,
	NO_PRESENCE
};

struct RegionTile {
	Climate climate = TEMPERATE_COLD;
	FeaturePresence mountains = NO_PRESENCE;
	FeaturePresence urban = LARGE_AREA;
	FeaturePresence rural = SPARSE;
	FeaturePresence woodland = SPARSE;
	FeaturePresence swamp = NO_PRESENCE;
	FeaturePresence water = NO_PRESENCE;
	//FLAG: 6 because hectagons being used for tiles, you may want to change
	bool coastal[6] = { false, false, false, false, false, false };

	//for water tiles
	bool isWaterTile = false;
	FeaturePresence underwaterCity = NO_PRESENCE;
	FeaturePresence floatingCity = NO_PRESENCE;
	FeaturePresence coralReef = NO_PRESENCE;
};

typedef struct Grid {
	suint width = 0;
	suint height = 0;
	Tile grid[MAX_WIDTH][MAX_HEIGHT];
};