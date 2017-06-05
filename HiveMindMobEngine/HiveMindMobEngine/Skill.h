#pragma once
#include <string>

using std::string;

enum SkillType : uint8_t {
	MISC_SKILL = 0,
	ACTIVE_COMBAT = 1,
	PASSIVE_COMBAT = 2,
	HACKER = 3,
	TECH = 4,
	SOFTWARE = 5,
	CONVERSATION = 6
};

struct Skill {
	SkillType type = MISC_SKILL;
	string name = "";
	string desc = "";
	int level = 1;
	int id;
};