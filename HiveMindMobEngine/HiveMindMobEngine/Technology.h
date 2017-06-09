#pragma once
#include <string>
#include "TypeDef.h"

using std::string;

const suint MAX_TECHS = 128;

enum TechType : uint8_t {
	MISC_TECH = 0,
	GENETIC_TECH = 1,
	BRAIN_IO_TECH = 2,
	AI_TECH = 3,
	ROBOTICS_TECH = 4,
	NETWORKING_TECH = 5,
	SOFTWARE_TECH = 6,
	WEAPONS_TECH = 7
};

struct Tech {
	string name = "DEFAULT_TECH_NAME";
	string desc = "DEFAULT_TECH_DESC";
	suint prereqs[4];
	suint id;
	TechType type = MISC_TECH;
	uint8_t level = 1;
};