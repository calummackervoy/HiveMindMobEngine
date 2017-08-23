#include "Character.h"

Character::Character() {
    //TODO: initialise cultures to NULL (in a general-purpose auxillary function?)
}

Character::Character(int seed) {
    this->seed = seed;
}

Character::Character(CharacterSave save) {

}

Character::~Character() {
    delete spriteManager;
}

CharacterSave Character::save() {
    
}

Trait Character::getTraitAt(int i) {
    if(i < 0 || i > MAX_TRAITS) throw std::exception("Index out of bounds");
    return traits[i];
}

Skill Character::getSkillAt(int i) {
    if(i < 0 || i > MAX_SKILLS) throw std::exception("Index out of bounds");
    return skills[i];
}

suint Character::getCultureAt(int i) {
    if(i < 0 || i > MAX_CULTURESPP) throw std::exception("Index out of bounds");
    return cultures[i] - 1;
}

int Character::addTrait(Trait t) {
    for(int i = 0; i < MAX_TRAITS; i++) {
        if(traits[i].id == -1) {
            t.id = i;
            traits[i] = t;
            return i;
        }
    }
    return -1;
}

int Character::addSkill(Skill s) {
    for(int i = 0; i < MAX_SKILLS; i++) {
        if(skills[i].id == -1) {
            s.id = i;
            skills[i] = s;
            return i;
        }
    }
    return -1;
}

int Character::addCulture(suint c) {
    for(int i = 0; i < MAX_CULTURESPP; i++) {
        if(cultures[i] == 0) {
            cultures[i] = c + 1;
            return i;
        }
    }
    return -1;
}

void Character::removeTrait(int i){
    if(i < 0 || i > MAX_TRAITS) return;
    traits[i].id = -1;
}

void Character::removeSkill(int i) {
    if(i < 0 || i > MAX_SKILLS) return;
    skills[i].id = -1;
}

void Character::removeCulture(int i) {
    if(i < 0 || i > MAX_CULTURESPP) return;
    cultures[i] = 0;
}