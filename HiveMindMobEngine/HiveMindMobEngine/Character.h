#pragma once
#include "Skill.h"

enum TraitType : uint8_t {

};

struct Trait {

};

const int MAX_TRAITS = 8;
const int MAX_SKILLS = 8;

class Character {
public:
	Character();
	//procedurally generate a character
	Character(int seed);
	~Character();

	int getSeed() {return seed;};
	inline int getLevel() {return level;};
	inline int getHomeRegion() {return homeRegion;};

	void setLevel(int val) {level = val;};

	inline int getTraitAt(int i);
	inline int getSkillAt(int i);
	inline int addTrait(Trait t);
	inline int addSkill(Skill s);
	inline void removeTrait(int i);
	inline void removeSkill(int i);

protected:
	Trait traits[8];
	Skill skills[8];
	int seed;
	int level;
	int homeRegion;
};