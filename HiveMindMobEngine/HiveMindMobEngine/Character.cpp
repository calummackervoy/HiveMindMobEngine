#include "Character.h"

Character::Character(Renderer* r, ResourceManager* rm, Wardrobe* w, FileHandler* file, int seed) {
	this->file = file;
    this->seed = seed;

	bodyTex = NULL;
	spriteManager = NULL;

	generateCharacter(r, rm, w);
}

Character::Character(Renderer* r, ResourceManager* rm, Wardrobe* w, FileHandler* file, string fileLocation) {
	this->file = file;

	spriteManager = NULL;
	bodyTex = NULL;

	readCharacterSave(r, rm, w, fileLocation);
}

Character::~Character() {
	clear();
}

void Character::clear() {
	delete spriteManager;
	delete bodyTex;
}

void Character::generateCharacter(Renderer* r, ResourceManager* rm, Wardrobe* w) {
	//make sure no memory will be leaked
	clear();

	//initialise sprite manager & give random clothing
	spriteManager = new CharacterSpriteManager(rm, w, r->getTexture(DEF_CHAR_SKIN));

	//TODO: initialise cultures to NULL (in a general-purpose auxillary function?)

	generateResolve(seed); //generate the resolve value using seed

	//TODO: FINISH ME
}

void Character::readCharacterSave(Renderer* r, ResourceManager* rm, Wardrobe* w, string fileLocation) {
	//make sure no memory will be leaked
	clear();

	file->openStream(fileLocation);

	age = (uint8_t)file->getNextInt();
	gender = (Gender)file->getNextInt();

	//stores how many of a trait type a character has
	int count;

	//one loop for each storage of traits
	//mental
	count = file->getNextInt();
	for (int i = 0; i < std::min(count, (int)MAX_TRAITS); i++) {
		mentalTraits[i] = (Trait)file->getNextInt();
	}
	//injury
	count = file->getNextInt();
	for (int i = 0; i < std::min(count, (int)MAX_TRAITS); i++) {
		injuryTraits[i] = (Trait)file->getNextInt();
	}
	//personality
	count = file->getNextInt();
	for (int i = 0; i < std::max(count, (int)MAX_TRAITS); i++) {
		personTraits[i] = (Trait)file->getNextInt();
	}
	//vulnerability
	count = file->getNextInt();
	for (int i = 0; i < std::max(count, (int)MAX_TRAITS); i++) {
		vulnTraits[i] = (Trait)file->getNextInt();
	}

	//TODO: copy skills, groups and cultures across

	//initialise a SpriteManager from the save
	string nextString = file->getNextString();
	if (nextString != "") {
		spriteManager = new CharacterSpriteManager(rm, w, r->getTexture(nextString));
		bodyTex = new string(nextString);
	}
	else {
		spriteManager = new CharacterSpriteManager(rm, w, r->getTexture(DEF_CHAR_SKIN));
		bodyTex = NULL;
	}

	//initialise a hat too if instructed
	count = file->getNextInt();
	if (count >= 0) {
		spriteManager->setHat(w->getHatAt(count));
		hatIndex = count;
	}
	else hatIndex = -1;

	//..and clothing
	count = file->getNextInt();
	if (count >= 0) {
		spriteManager->setClothing(w->getClothingAt(count));
		clothingIndex = count;
	}
	else clothingIndex = -1;

	//finally read the seed value
	seed = file->getNextInt();

	file->closeStream();

	//generate resolve
	generateResolve(seed);
}

void Character::save() {
	//TODO
}

Trait Character::getTraitAt(TraitType type, int i) {
	//bounds checking
	if (i < 0 || i > MAX_TRAITS) {
		Logger::logError("Character", "i param to getTraitAt was out of bounds");
		return TRAIT_NULL;
	}

	switch (type) {
	case TRAIT_TYPE_MENTAL:
		return mentalTraits[i];
	case TRAIT_TYPE_INJURY:
		return injuryTraits[i];
	case TRAIT_TYPE_PERSONALITY:
		return personTraits[i];
	case TRAIT_TYPE_VULNERABILITY:
		return vulnTraits[i];
	}

	Logger::logError("Character", "TraitType passed to getTraitAt which was not handled");
	return TRAIT_NULL;
}

int Character::addTrait(TraitType type, Trait t) {
    for(int i = 0; i < MAX_TRAITS; i++) {
		switch (type) {
		case TRAIT_TYPE_MENTAL:
			if (mentalTraits[i] == TRAIT_NULL) {
				mentalTraits[i] = t;
				return i;
			}
			break;

		case TRAIT_TYPE_INJURY:
			if (injuryTraits[i] == TRAIT_NULL) {
				injuryTraits[i] = t;
				return i;
			}
			break;

		case TRAIT_TYPE_PERSONALITY:
			if (personTraits[i] == TRAIT_NULL) {
				personTraits[i] = t;

				//if brave/coward generate new resolve
				if (t == TRAIT_PERSON_BRAVE || t == TRAIT_PERSON_COWARD) {
					generateResolve();
				}
				return i;
			}
			break;

		case TRAIT_TYPE_VULNERABILITY:
			if (vulnTraits[i] == TRAIT_NULL) {
				vulnTraits[i] = t;
				return i;
			}
			break;

		default:
			return -1;
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

void Character::removeTrait(TraitType type, int i){
    if(i < 0 || i > MAX_TRAITS) return;
	switch (type) {
	case TRAIT_TYPE_MENTAL:
		mentalTraits[i] = TRAIT_NULL;
		break;
	case TRAIT_TYPE_INJURY:
		injuryTraits[i] = TRAIT_NULL;
		break;
	case TRAIT_TYPE_PERSONALITY:
		personTraits[i] = TRAIT_NULL;
		break;
	case TRAIT_TYPE_VULNERABILITY:
		vulnTraits[i] = TRAIT_NULL;
		break;
	}
}

void Character::removeSkill(int i) {
    if(i < 0 || i > MAX_SKILLS) return;
    skills[i].id = -1;
}

void Character::removeCulture(int i) {
    if(i < 0 || i > MAX_CULTURESPP) return;
    cultures[i] = 0;
}

bool Character::hasTrait(Trait t, TraitType type) {
	Trait check;
	for (int i = 0; i < MAX_TRAITS; i++) {
		check = getTraitAt(type, i);
		if (check == t) return true;
	}
	return false;
}

//TODO
ExploitResponse Character::exploit(SocialEngineeringAction action,
		SocialEngineeringMethod method, ToleranceLevel demand, ToleranceLevel strengthLevel) {
	int likelihoodTrue = 0; //start at certain fail
	
	//calculate base likelihood
							
	//percentage increase to likelihood
	float percentIncrease = 0.0f;
	float percentDecrease = 0.0f;
	
	switch (action) {
	case SOCIAL_ALLOW_ACCESS:

		break;
	case SOCIAL_GAIN_INFO:
		
		break;
	case SOCIAL_GIVE_PASS:
		
		break;
	}

	//calculate final success/failure

	return{};
}

void Character::generateResolve(int seed) {
	//start resolve at a base value
	suint r = 200;

	//factor in traits which affect this
	//brave/coward
	if (hasTrait(TRAIT_PERSON_BRAVE, TRAIT_TYPE_PERSONALITY)) {
		r += randSuint(50, 150, seed);
	}
	else if (hasTrait(TRAIT_PERSON_COWARD, TRAIT_TYPE_PERSONALITY)) {
		r -= randSuint(50, 150, seed);
	}

	//generate random number for remaining courage for normal range
	else {
		switch (randInt(0, 1, seed)) {
		case 0:
			r -= randSuint(1, 50, seed);
		case 1:
			r += randSuint(1, 50, seed);
		}
	}

	//set this as the resolve
	resolve = r;
}