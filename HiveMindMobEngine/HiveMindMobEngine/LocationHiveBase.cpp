#include "LocationHiveBase.h"

LocationHiveBase::LocationHiveBase(int id, LocationHiveBaseSave params)
	: Location(id, params) {
    this->id = id;
    this->name = params.name;
    this->ownerGroupId = params.ownerGroupId;
    this->type = params.type;
    this->destroyed = params.destroyed;
    this->isExclusive = params.isExclusive;
}

/*LocationHiveBase::LocationHiveBase(int seed) {
}*/

LocationHiveBase::~LocationHiveBase() {

}

Item LocationHiveBase::getItemAt(int i) {
    if(i < 0 || i >= MAX_STORAGE) throw std::exception("Index out of bounds");
    return inventory[i];
}

int LocationHiveBase::addItem(Item it) {
    for(int i = 0; i < MAX_STORAGE; i++) {
        if(inventory[i].id == -1) {
            it.id = i;
            inventory[i] = it;
            return i;
        }
    }
    return -1;
}

void LocationHiveBase::removeItem(int i){
    if(i < 0 || i >= MAX_STORAGE) return;
    inventory[i].id = -1;
}