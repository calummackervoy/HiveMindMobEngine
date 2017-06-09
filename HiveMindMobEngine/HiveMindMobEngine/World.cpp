#include "World.h"

World::World(WorldParams params) {
    techs = FileHandler::readTechConfig(string params.techConfig);
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
        if(techs[i].id == -1) {
            t.id = i;
            techs[i] = t;
            return i;
        }
    }
    return -1;
}

void World::removeTech(int i) {
    if(i < 0 || i >= MAX_TECHS) return;
    techs[i].id = -1;
}