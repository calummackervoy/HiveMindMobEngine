#pragma once
#include "Typedef.h"
#include "ToleranceLevel.h"

//Author: Calum Mackervoy
//Purpose: To keep track of different progress-related mechanisms

const suint MAX_PROGRESS = 128;
const suint PROGRESS_MAX_PRE_REQS = 4;

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

struct Progress {
	std::string name = "DEFAULT_NAME";
	std::string desc = "DEFAULT_DESC";
	sint prereqs[4] = { -1,-1,-1,-1 };
	sint id = -1; //flags null progress
	uint8_t type = 0;
	uint8_t level = 1;
	ToleranceLevel powerRating = TOLERANCE_MEDIUM;
	ToleranceLevel costRating = TOLERANCE_MEDIUM;
	bool active = false;
};