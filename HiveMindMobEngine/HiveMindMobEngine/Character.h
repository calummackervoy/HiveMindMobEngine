#pragma once
#include "Tools.h"
#include "rand.h"
#include "Skill.h"
#include "Group.h"
#include "CharacterSpriteManager.h"
#include "Gender.h"
#include "Culture.h"
#include "Save.h"
#include "Emotion.h"
#include "Hack.h"

//TODO: disabilities?
enum Trait : uint8_t {
	TRAIT_NULL,

	//mental conditions
	//TRAIT_MENTAL_PSYCOPATHIC,
	TRAIT_MENTAL_DEPRESSION,
	TRAIT_MENTAL_ANXIETY,
	TRAIT_MENTAL_AUTISM,
	TRAIT_MENTAL_PTSD,
	//TRAIT_MENTAL_NAPOLEON,
	//TRAIT_MENTAL_ANGER,
	//TRAIT_MENTAL_ADDICTION, //TODO: how to specify what?
	//TRAIT_MENTAL_MESSIAH,
	//TRAIT_MENTAL_NARCASSIST,

	//injury / imparement
	TRAIT_INJURY_MEMORY,
	//TRAIT_INJURY_MOVEMENT,
	//TRAIT_INJURY_JUDGEMENT,
	//TRAIT_INJURY_WEAKNESS,
	//TRAIT_INJURY_DISTRACTION,

	//personality
	TRAIT_PERSON_AGGRESSIVE,
	//TRAIT_PERSON_SYMPATHETIC,
	//TRAIT_PERSON_RUDE,
	//TRAIT_PERSON_JUDGEMENTAL,
	//TRAIT_PERSON_GOAT,
	TRAIT_PERSON_BRAVE,
	TRAIT_PERSON_COWARD,

	//vulnerabilities
	TRAIT_VULN_BLACKMAIL,
	TRAIT_VULN_COERCE,
	TRAIT_VULN_BRIBE
};
enum TraitType : uint8_t {
	TRAIT_TYPE_NULL,
	TRAIT_TYPE_MENTAL,
	TRAIT_TYPE_INJURY,
	TRAIT_TYPE_PERSONALITY,
	TRAIT_TYPE_VULNERABILITY
};

const uint8_t MAX_TRAITS = 8;
const uint8_t MAX_SKILLS = 16;

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
	inline Emotion getExpression() {return spriteManager->getExpression();};

	//void setLevel(int val) {level = val;};
	inline void setGender(Gender val) {gender = val;};
	inline void setExpression(Emotion e) {spriteManager->setExpression(e);};

	inline Trait getTraitAt(TraitType type, int i);
	inline Skill getSkillAt(int i);
	inline suint getCultureAt(int i);
	inline int addTrait(TraitType type, Trait t);
	inline int addSkill(Skill s);
	inline int addCulture(suint c);
	inline void removeTrait(TraitType type, int i);
	inline void removeSkill(int i);
	inline void removeCulture(int i);

	//function to check whether has a certain trait
	bool hasTrait(Trait t, TraitType type);

	//hacking.. (high level part)
	ExploitResponse exploit(SocialEngineeringAction action,
		SocialEngineeringMethod method,
		ToleranceLevel demand,
		ToleranceLevel strengthLevel);

protected:
	//trait categories
	Trait mentalTraits[MAX_TRAITS];
	Trait injuryTraits[MAX_TRAITS];
	Trait personTraits[MAX_TRAITS]; //personality
	Trait vulnTraits[MAX_TRAITS]; //vulnerabilities (social engineering)
	suint resolve;

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

	//internal function to generate a resolve
	void generateResolve(int seed = -1);
};