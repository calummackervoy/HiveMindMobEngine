#pragma once
#include "Location.h"
#include "TypeDef.h"
#include "Item.h"

const suint MAX_STORAGE = 32;

struct LocationHiveBaseSave : LocationSave {
	Item inventory[MAX_STORAGE];
};

class LocationHiveBase : protected Location {
public:
	LocationHiveBase(int id, LocationHiveBaseSave params = {});
	~LocationHiveBase();

	inline Item getItemAt(int i);
	inline int addItem(Item it);
	inline void removeItem(int i);

protected:
	Item inventory[MAX_STORAGE];
};