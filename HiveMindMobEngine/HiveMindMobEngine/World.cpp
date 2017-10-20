#include "World.h"

World::World(WorldParams params) {
	//sanitise inputs
	if (!sanitiseWorldParams(params)) {
		throw std::exception("World Params were invalid! Check console for details");
	}

	//setup a general world picture
	generalisedWorldGen(params);

	//setup specific regions with this world context

}

void World::generalisedWorldGen(WorldParams params) {
	//generate or load the world map (depending on WorldParam instructions)
	//map = new MapWorld(params);

	//setup each component of the world picture as a whole, bit by bit
	//technology
	//TODO: convert techs from generic config
	//techs = FileHandler::readTechConfig(string params.techConfig);#

	//initialise tech positions to 1

}

World::World(WorldSave save) {

}

/*World::World(int seed) {
}*/

World::~World() {

}

Region* World::getRegionAt(suint i) {
    if(i > MAX_REGIONS) throw std::exception("Index out of bounds");
    return regions[i];
}

Culture* World::getCultureAt(suint i) {
    if(i > MAX_CULTURES) throw std::exception("Index out of bounds");
    return cultures[i];
}

int World::addCulture(Culture* c) {
    for(int i = 0; i < MAX_CULTURES; i++) {
        if(cultures[i] == NULL) {
            cultures[i] = c;
            return i;
        }
    }
    return -1;
}

void World::removeCultureAt(suint i) {
    if(i > MAX_CULTURES) return;
    delete cultures[i];
    cultures[i] = NULL;
}

void World::addMonth() {
    if(dateTime.month == 12) {
        addYear();
        dateTime.month = 1;
    }
    else dateTime.month++;
}

void World::addDay() {
    switch(dateTime.month) {
    //months with 31
    case 1: case 3: case 5: case 7:
    case 8: case 10: case 12:
        if(dateTime.day == 31) {
            addMonth();
            dateTime.day = 1;
        }
        else dateTime.day++;
        break;
    //months with 30
    case 4: case 6: case 9: case 11:
        if(dateTime.day == 30) {
            addMonth();
            dateTime.day = 1;
        }
        else dateTime.day++;
        break;
    //and February
    case 2:
        //is it leap year?
        bool leapYear = ((dateTime.year % 4) == 0);
        if((!leapYear && dateTime.day == 28) ||
            (leapYear && dateTime.day == 29)) {
            addMonth();
            dateTime.day = 1;
        }
        else dateTime.day++;
        break;
    }
}

void World::addHour() {
    if(dateTime.hour == 24) {
        addDay();
        dateTime.hour = 1;
    }
    else dateTime.hour++;
}

bool World::sanitiseWorldParams(WorldParams params) {
	//TODO
	return true;
}