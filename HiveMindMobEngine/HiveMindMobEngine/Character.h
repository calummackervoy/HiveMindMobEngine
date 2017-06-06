#pragma once
#include "Skill.h"

enum TraitType : uint8_t {

};

struct Trait {

};

const uint8_t MAX_TRAITS = 8;
const uint8_t MAX_SKILLS = 8;

class Character {
public:
	Character();
	//procedurally generate a character
	Character(int seed);
	~Character();

	uint getSeed() {return seed;};
	inline uint getHomeRegion() {return homeRegion;};
	inline uint8_t getLevel() {return level;};
	inline uint8_t getAge() {return age;};

	void setLevel(int val) {level = val;};

	inline Trait getTraitAt(int i);
	inline Skill getSkillAt(int i);
	inline int addTrait(Trait t);
	inline int addSkill(Skill s);
	inline void removeTrait(int i);
	inline void removeSkill(int i);

protected:
	Trait traits[8];
	Skill skills[8];
	uint seed;
	uint homeRegion;
	uint8_t level;
	uint8_t age;
};