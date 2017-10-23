#pragma once
#include "Group.h"
#include "Rand.h"
#include "MapRegion.h"
#include "Organisation.h"

using std::endl;

const suint MAX_GROUPS = 64;
const suint MAX_COUNTRY_SIZE = 16;
const suint MAX_REGIONAL_CULTURES = MAX_GROUPS;

struct Country {
	std::string name = "DEFAULT_COUNTRY";
	int numRegions = 2;
	int regionIds[MAX_COUNTRY_SIZE];
};

struct RegionConfig {
	
};

//TODO: starting tech level -> species
//TODO: define authority culture
struct RegionConfigRand {
	GroupTypeBias groupTypeBias;
	uint population = 1000;
	suint targetNumGroups = 50;
	AutonomyLevel autonomy = HEIRARCHY;
	GenderBias dominantGenderBias = GENDERBIAS_NONE;
	ToleranceLevel cultureDiversity = TOLERANCE_VERY_LOW;
	ToleranceLevel povertyLevel = TOLERANCE_MEDIUM;
	GenerationMode generationMode = STABLE_POWER;
};

class Region {
public:
	Region(ResourceManager* rm, int id, RegionConfig config = {});
	//procedurally generate a region from spec
	Region(ResourceManager* rm, int id, int seed, RegionConfigRand config = {});
	~Region();

	inline uint getId() {return id;};
	inline uint getRegionAuthority() {return regionAuthority;};

	//generating region's groups and loading into focus
	void load();

protected:
	//MapRegion* map;
	uint id;
	uint regionAuthority;
	uint population;
	bool inStruggle;

	//TODO
	//auxillary functions for generating
	//generating geography

	//generating population
};