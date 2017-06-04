#pragma once
#include <string>
#include "Drug.h"

using std::string;

struct Item {
	string name = "DEFAULT_ITEM_NAME";
	string desc = "DEFAULT_ITEM_DESC";
	int val = 1;
};

struct Weapon : Item {
	
};

struct Consumable : Item {
	DrugType type = DEF_DRUGTYPE;
	bool legal = true;
};