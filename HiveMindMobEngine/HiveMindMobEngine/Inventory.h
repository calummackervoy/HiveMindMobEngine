#pragma once
#include "Item.h"
#include "Typedef.h"

//Author: Calum Mackervoy
//Purpose: Inventory system

const suint MAX_INV_ITEMS = 64;

class Inventory {
public:
    Inventory();
    ~Inventory();

    inline Item* getItem(suint i);
    inline suint addItem(Item &item);
    inline void removeItem(suint i);
protected:
    Item* inv[MAX_INV_ITEMS];
};