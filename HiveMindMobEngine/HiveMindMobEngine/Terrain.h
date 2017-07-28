#pragma once
#include <SFML\Graphics.hpp>
#include "Typedef.h"
#include "Freerun.h"

const uint8_t MAX_WIDTH = 1000;
const uint8_t MAX_HEIGHT = 1000;

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