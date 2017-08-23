#pragma once
#include "Skill.h"
#include "Group.h"
#include "CharacterSpriteManager.h"
#include "Gender.h"
#include "Culture.h"
#include "Save.h"

enum Trait : uint8_t {
	TRAIT_TYPE_NULL = 0;
};

const uint8_t MAX_TRAITS = 8;
const uint8_t MAX_SKILLS = 16;

//TODO: addictions?
//TODO: how to handle inventory on the cheap
//TODO: needs to remember locations etc
//TODO: personality?
//TODO: AI agent (FSM)
//TODO: race?

class Character {
public:
	Character();
	//procedurally generate a character
	Character(int seed);
	//load a saved character
	Character(CharacterSave save);
	~Character();

	//save a character
	CharacterSave save();

	uint getSeed() {return seed;};
	inline uint getHomeRegion() {return homeRegion;};
	//inline uint8_t getLevel() {return level;};
	inline uint8_t getAge() {return age;};
	inline CharacterSpriteManager* getSpriteManager() {return spriteManager;};
	inline Gender getGender() {return gender;};

	//void setLevel(int val) {level = val;};
	inline void setGender(Gender val) {gender = val;};

	inline Trait getTraitAt(int i);
	inline Skill getSkillAt(int i);
	inline suint getCultureAt(int i);
	inline int addTrait(Trait t);
	inline int addSkill(Skill s);
	inline int addCulture(suint c);
	inline void removeTrait(int i);
	inline void removeSkill(int i);
	inline void removeCulture(int i);

protected:
	Trait traits[MAX_TRAITS];
	//TODO: pointers for below?
	Skill skills[MAX_SKILLS];
	Group groups[MAX_GROUPSPP];
	suint cultures[MAX_CULTURESPP]; //points to index in world state array
	CharacterSpriteManager* spriteManager;
	uint seed; //TODO: maintaining consistent state?
	uint homeRegion;
	//uint8_t level;
	Gender gender;
	uint8_t age;
};