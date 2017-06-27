#include "World.h"

World::World(WorldParams params) {
	//TODO: convert techs from generic config
    //techs = FileHandler::readTechConfig(string params.techConfig);
}

/*World::World(int seed) {
}*/

World::~World() {

}

Tech* World::getTechAt(int i) {
    if(i < 0 || i >= MAX_TECHS) throw std::exception("Index out of bounds");
    return techs[i];
}

int World::addTech(Tech* t) {
    for(int i = 0; i < MAX_TECHS; i++) {
        if(techs[i]->id == -1) {
            t->id = i;
            techs[i] = t;
            return i;
        }
    }
    return -1;
}

void World::removeTech(int i) {
    if(i < 0 || i >= MAX_TECHS) return;
    techs[i]->id = -1;
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