#include "Region.h"

Region::Region(int id, RegionConfig config) {
    this->id = id;
}

struct RegionConfigRand {
	GroupTypeBias groupTypeBias;
	uint population = 1000;
	suint targetNumGroups = 50;
	AutonomyLevel autonomy = HIERARCHY;
	GenderBias dominantGenderBias = GENDERBIAS_NONE;
	ToleranceLevel cultureDiversity = TOLERANCE_VERY_LOW;
	ToleranceLevel povertyLevel = TOLERANCE_MEDIUM;
	GenerationMode generationMode = STABLE_POWER;
};

Region::Region(int id, int seed, RegionConfigRand config) {
    this->id = id;

    //people belong to multiple groups of different types
    uint popJobs = config.population;
    uint popCulture = randInt(config.population, config.population * MAX_GROUPSPP);
    uint popPolitical = randInt(config.population / 100, config.population * MAX_GROUPSPP);

    //generate map
    //size it to suit population + growth

    //generate locations

    //enough housing for population and room for growth

    //institutions to suit size & population

    //generate groups
    //
}

Region::~Region() {

}

void Region::load() {
    
}