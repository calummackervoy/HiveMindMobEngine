/*#pragma once
#include "Save.h"
#include "RendererConfig.h"

class Location {
public:
	Location(int id, LocationSave params = {});
	//procedurally generate a Location?
	//Location(int seed);
	~Location();

protected:
	Element graphic;
	std::string name;
	uint id;
	uint ownerGroupId;
	LocationType type;
	bool destroyed;
	bool isExclusive;
};*/