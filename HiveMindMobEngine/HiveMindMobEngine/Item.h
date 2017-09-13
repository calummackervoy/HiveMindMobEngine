#pragma once
#include "Typedef.h"
#include <string>
#include "Drug.h"

using std::string;

enum ItemType : uint8_t {
	ITEM_NULL,
	ITEM_WEAPON,
	ITEM_CONSUMABLE,
	ITEM_EQUIPMENT,
	ITEM_VULNERABILITY //TODO: ??
};

struct Item {
	string name = "DEFAULT_ITEM_NAME";
	string desc = "DEFAULT_ITEM_DESC";
	int val = 1;
	sint id = -1;
	ItemType type = ITEM_NULL;
};

struct Weapon : Item {
	
};

struct Consumable : Item {
	DrugType type = DEF_DRUGTYPE;
	bool legal = true;
};

//an item which allows a certain task to be completed
//can be hardware or software or a combination
struct Equipment : Item {

};