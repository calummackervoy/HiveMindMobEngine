#pragma once
#include "Region.h"
#include "Technology.h"
#include "FileHandler.h"
#include "Config.h"

//TODO: replace all const ints with uint8_t where necessary
const int MAX_REGIONS = 32;

class World {
public:
	World(WorldParams params);
	//procedurally generate a World?
	//World(int seed);
	~World();

	inline Tech* getTechAt(int i);
	inline int addTech(Tech* t);
	inline void removeTech(int i);

protected:
	Region* regions[MAX_REGIONS];
	Tech* techs[MAX_TECHS];
};