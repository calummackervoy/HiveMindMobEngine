#pragma once
#include "Region.h"

//TODO: replace all const ints with byte where necessary
const int MAX_REGIONS = 32;

class World {
public:
	World();
	//procedurally generate a World?
	//World(int seed);
	~World();

protected:
	Region regions[MAX_REGIONS];
};