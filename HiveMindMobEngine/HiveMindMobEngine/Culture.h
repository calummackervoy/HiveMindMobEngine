#pragma once
#include <string>
#include "Drug.h"

using std::string;

enum SpeciesType : uint8_t {
	HUMAN = 0,
	COMPUTER = 1,
	MUTANT = 2
};

enum SkinTone : uint8_t {

};

enum ToleranceLevel : uint8_t {
	TOLERANCE_VERY_HIGH = 0,
	TOLERANCE_HIGH = 1,
	TOLERANCE_MEDIUM = 2,
	TOLERANCE_LOW = 3,
	TOLERANCE_VERY_LOW = 4,
	TOLERANCE_ZERO = 5
};

enum GenderBias : uint8_t {
	GENDERBIAS_NONE = 0,
	PATRIACHAL = 1,
	MATRIACHAL = 2,
	SLIGHT_PATRIACHAL = 3,
	SLIGHT_MATRIACHAL = 4
};

enum ReligionType : uint8_t {
	ATHEIST = 0,
	AGNOSTIC = 1,
	ANIMIST = 2,
	FETISHIST = 3,
	DEITY = 4
};

enum Activity : uint8_t {
	NO_ACTIVITY = 0,
	MUSIC_GENRE = 1,
	PHILOSOPHY = 2,
	SPORT_PLAY = 3,
	SPORT_OBSERVE = 4,
	GAMING = 5,
	TECHNOLOGY = 6
};

struct Race {

};

struct Religion {
	Religion* parent = NULL;
	ReligionType type = ATHEIST;
};

struct Culture {
	string name = "DEFAULT_CULTURE";
	string desc = "DEFAULT_CULTURE_DESC";
	Culture* parent = NULL;
	Religion religion;
	DrugType drug = DEF_DRUGTYPE;
	GenderBias genderBias = GENDERBIAS_NONE;
	Activity activity = NO_ACTIVITY;
	ToleranceLevel siblingCulture = TOLERANCE_VERY_HIGH;
	ToleranceLevel similarCulture = TOLERANCE_HIGH;
	ToleranceLevel awareCulture = TOLERANCE_MEDIUM;
	ToleranceLevel foreignCulture = TOLERANCE_MEDIUM;
	ToleranceLevel contradictingCulture = TOLERANCE_LOW;
	bool isCommunal = false;
	bool isFighter = false;
	bool isChildhood = false;
};