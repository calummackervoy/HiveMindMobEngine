#pragma once
#include "RenderConfig.h"
#include <string>

using std::string;

enum LocationType : uint8_t {
	MISC_LOCATION,
	AUTHORITY,
	SECRET_BASE,
	HOUSING,
	HOSPITAL,
	PRODUCTIVE_LOCATION,
	CONSUMPTION_LOCATION,
	CULTURAL_LOCATION,
	TRANSPORT_LOCATION,
	PUBLIC_LOCATION,
	PRISON,
	FORCED_LABOUR_CAMP,
	EXTERMINATION_CAMP
};

struct LocationSave {
	string name = "DEFAULT_NAME";
	string textureLocation;
	uint ownerGroupId;
	LocationType type = MISC_LOCATION;
	bool destroyed = false;
	bool isExclusive = false;
};

class Location {
public:
	Location(int id, LocationSave params = {});
	//procedurally generate a Location?
	//Location(int seed);
	~Location();

protected:
	Element graphic;
	string name;
	uint id;
	uint ownerGroupId;
	LocationType type;
	bool destroyed;
	bool isExclusive;
};