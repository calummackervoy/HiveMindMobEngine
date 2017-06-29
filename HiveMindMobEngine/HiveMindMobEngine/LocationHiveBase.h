#pragma once
#include "Location.h"
#include "TypeDef.h"
#include "Item.h"

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