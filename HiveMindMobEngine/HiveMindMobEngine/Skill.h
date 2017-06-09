#pragma once
#include <string>
#include "TypeDef.h"

using std::string;

enum SkillType : uint8_t {
	MISC_SKILL = 0,
	ACTIVE_COMBAT = 1,
	PASSIVE_COMBAT = 2,
	HACKER = 3,
	TECH = 4,
	SOFTWARE = 5,
	CONVERSATION = 6,
	PERCEPTION = 7,
	KNOWLEDGE = 8
};

enum KnowledgeType : uint8_t {
	NULL_KNOWLEDGE,
	AGRICULTURE_KNOWLEDGE,
	CARPENTRY_KNOWLEDGE,
	CONSTRUCTION_KNOWLEDGE,
	ESPIONAGE,
	HACK_BRAINIO,
	HACK_MONITORS,
	HACK_NETWORKS,
	HACK_ROBOTICS,
	HACK_SINGLE_SYSTEM,
	MARTIAL_ARTS_KNOWLEDGE,
	STRATEGY_RURAL,
	STRATEGY_URBAN,
	SURVIVAL_KNOWLEDGE
};

struct Skill {
	string name = "";
	string desc = "";
	suint level = 1;
	suint id;
	SkillType type = MISC_SKILL;
	KnowledgeType knowledge = NULL_KNOWLEDGE;
};