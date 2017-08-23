#pragma once
#include "Typedef.h"
#include "Item.h"

//Author: Calum Mackervoy
//Purpose: Define the different structures for saved data reading/writing

struct WorldSave {

};

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

const suint MAX_STORAGE = 32;

struct LocationHiveBaseSave : LocationSave {
	Item inventory[MAX_STORAGE];
};

struct CharacterSave {
	//TODO
};