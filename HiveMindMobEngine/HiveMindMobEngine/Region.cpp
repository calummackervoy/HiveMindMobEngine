#include "Region.h"

Region::Region(ResourceManager* rm, int id, RegionConfig config) {
    this->id = id;
	this->map = new MapRegion(rm,"");
}

//TODO: finish semantic generation
Region::Region(ResourceManager* rm, int id, int seed, RegionConfigRand config) {
	this->map = new MapRegion(rm, "");
    this->id = id;
	cout << "Generating a region..." << endl;
	cout << "  Generating the graphics.." << endl;


	cout << "  Generating the geography.." << endl;

	//generate map
	//size it to suit population + growth

	//generate locations

	//enough housing for population and room for growth

	//institutions to suit size & population

	cout << "  Generating the peeps.." << endl;

    //people belong to multiple groups of different types
    uint popJobs = config.population;
	cout << "\tpopulation read in as " << popJobs << endl;
    uint popCulture = randInt(config.population, config.population * MAX_GROUPSPP);
	cout << "\tcultural population randomly chosen as " << popCulture << endl;
    uint popPolitical = randInt(config.population / 100, config.population * MAX_GROUPSPP);
	cout << "\tpolitical population randomly chosen as " << popPolitical << endl;

    //generate groups
    //
}

Region::~Region() {

}

void Region::load() {
    
}