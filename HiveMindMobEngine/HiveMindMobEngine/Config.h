#pragma once
#include "Map.h"
#include "Organisation.h"
#include "Culture.h"
#include <string>

using std::string;

enum WealthGrowth : uint8_t {
	DECLINE_RAPID,
	DECLINE_GRADUAL,
	DECLINE_SMOOTH,
	OSCILLATING_GROWTH,
	GROWTH_SMOOTH,
	GROWTH_GRADUAL,
	GROWTH_RAPID
};

struct WorldParams {
	MapConfig mapGen = {};
	string techConfig = "";
	string map = "";
	suint numRegions = 32;
	GenerationMode worldPower = STABLE_POWER;
	WealthGrowth growth = OSCILLATING_GROWTH;
	ToleranceLevel povertyLevel = TOLERANCE_MEDIUM;
	GenderBias dominantGenderBias = GENDERBIAS_NONE;
	bool centralisedEmpire = false;
	bool generateMap = true;
};

struct GameConfig {
    WorldParams worldParams;
};

enum EngineResponseCode : uint8_t {

};

struct EngineResponse {
    EngineResponseCode responseCode;
};