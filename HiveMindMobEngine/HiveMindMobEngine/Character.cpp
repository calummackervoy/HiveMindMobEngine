#include "Character.h"

Character::Character() {

}

Character::Character(int seed) {
    this->seed = seed;
}

Character::~Character() {

}

Trait Character::getTraitAt(int i) {
    if(i < 0 || i > MAX_TRAITS) throw std::exception("Index out of bounds");
    return traits[i];
}

Skill Character::getSkillAt(int i) {
    if(i < 0 || i > MAX_SKILLS) throw std::exception("Index out of bounds");
    return skills[i];
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
        if(skill[i].id == -1) {
            s.id = i;
            skills[i] = s;
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