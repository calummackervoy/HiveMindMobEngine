#pragma once
#include <algorithm>
#include "FileHandler.h"
#include "Renderer.h"
#include "CharacterGameSprite.h"
#include "Tools.h"
#include "rand.h"
#include "Skill.h"
#include "Group.h"
#include "Gender.h"
#include "Culture.h"
#include "Emotion.h"
#include "Hack.h"
#include "Trait.h"

const uint8_t MAX_TRAITS = 8;
const uint8_t MAX_SKILLS = 16;

//TODO: store config location
class Character {
public:
	//procedurally generate a character
	Character(Renderer* r, ResourceManager* rm, FileHandler* file, int seed = -1);
	//load a saved character
	Character(Renderer* r, ResourceManager* rm, FileHandler* file, std::string fileLocation);
	~Character();

	//TODO: reset a character (or initialise) by a generated seed
	void generateCharacter(Renderer* r, ResourceManager* rm);
	//reset a character (or initialise) according to a saved one
	void readCharacterSave(Renderer* r, ResourceManager* rm, std::string fileLocation);

	//save a character
	void save(std::string location);

	uint getSeed() {return seed;};
	//inline uint getHomeRegion() {return homeRegion;};
	//inline uint8_t getLevel() {return level;};
	inline uint8_t getAge() {return age;};
	inline Gender getGender() {return gender;};
	inline Emotion getExpression() {return sprite->getExpression();};
	inline CharacterGameSprite* getSprite() { return sprite; };

	//void setLevel(int val) {level = val;};
	inline void setGender(Gender val) {gender = val;};
	inline void setExpression(Emotion e) {sprite->setExpression(e);};

	Trait getTraitAt(TraitType type, int i);
	inline Skill getSkillAt(int i) {
		if (i < 0 || i > MAX_SKILLS) throw std::exception("Index out of bounds");
		return skills[i];
	}
	inline suint getCultureAt(int i) {
		if (i < 0 || i > MAX_CULTURESPP) throw std::exception("Index out of bounds");
		return cultures[i] - 1;
	}
	int addTrait(TraitType type, Trait t);
	int addSkill(Skill s);
	int addCulture(suint c);
	void removeTrait(TraitType type, int i);
	void removeSkill(int i);
	void removeCulture(int i);

	//function to check whether has a certain trait
	bool hasTrait(Trait t, TraitType type);
	//TODO: hasSkill?
	//TODO: hasCulture?

	//function to generate a new resolve value
	void generateResolve(int seed = -1);

	//hacking.. (high level part)
	ExploitResponse exploit(SocialEngineeringAction action,
		SocialEngineeringMethod method,
		ToleranceLevel demand,
		ToleranceLevel strengthLevel);

protected:
	std::string name;
	//trait categories
	Trait mentalTraits[MAX_TRAITS];
	Trait injuryTraits[MAX_TRAITS];
	Trait personTraits[MAX_TRAITS]; //personality
	Trait vulnTraits[MAX_TRAITS]; //vulnerabilities (social engineering)
	FileHandler* file;
	suint resolve;

	//TODO: pointers for below?
	Skill skills[MAX_SKILLS];
	Group groups[MAX_GROUPSPP];
	suint cultures[MAX_CULTURESPP]; //points to index in world state array

	//TODO
	//string* saveLocation; //location on disk the character is to be saved in

	//character sprite to manage expression, clothing etc
	CharacterGameSprite* sprite;
	//storage of body, hat & clothing textures
	std::string bodyTex;
	std::string hatOptions;
	std::string topOptions;
	std::string bottomOptions;

	uint seed; //TODO: maintaining consistent state?
	//uint homeRegion;
	//uint8_t level;
	Gender gender;
	uint8_t age;

	//utility function to clear a character's memory
	void clear();

	//function to dress character based on index & config provided
	void dress(Renderer* r, int hatIndex, int topIndex, int bottomIndex);
	void dress(Renderer* r); //overload to randomly select
};