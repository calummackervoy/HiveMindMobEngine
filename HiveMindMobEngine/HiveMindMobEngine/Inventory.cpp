#include "Inventory.h"

Inventory::Inventory() {
    //init inventory to NULL
    for(int i = 0; i < MAX_INV_ITEMS; i++) {
        inv[i] = NULL;
    }
}

Inventory::~Inventory() {
    delete[] inv;
}

Item* Inventory::getItem(suint i) {
    //bounds checking
	if (i > MAX_INV_ITEMS) throw std::exception("Index out of bounds");
	return inv[i];
}

suint Inventory::addItem(Item &item) {
    for (int i = 0; i < MAX_INV_ITEMS; i++) {
		if (inv[i] == NULL) {
			inv[i] = new Item(item);
			item.id = i;
			return i;
		}
	}
	return -1;
}

void Inventory::removeItem(suint i) {
    //bounds checking
	if (i > MAX_INV_ITEMS) return;
	if (inv == NULL || inv[i] == NULL) return;

	delete inv[i];
	inv[i] = NULL;
}