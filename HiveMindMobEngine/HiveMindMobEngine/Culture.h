#pragma once
#include "Drug.h"
#include "Ethnicity.h"
#include "ToleranceLevel.h"
#include "Typedef.h"

const suint MAX_CULTURESPP = 4;
const uint MAX_CULTURES = 64;

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
	DEITY_SINGULAR = 4,
	DEITY_MANY = 5
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

enum Caste : uint8_t {
	NO_CLASS_DISTINCTION,
	REFUGEE,
	HOMELESS,
	LOWER_CLASS,
	WORKING_CLASS,
	LOWER_MIDDLE_CLASS,
	UPPER_MIDDLE_CLASS,
	NEW_MONEY_CLASS,
	OLD_MONEY_CLASS,
	ACADEMIC_CLASS
};

struct Religion {
	Religion* parent = NULL;
	ReligionType type = ATHEIST;
};

struct Culture {
	std::string name = "DEFAULT_CULTURE";
	std::string desc = "DEFAULT_CULTURE_DESC";
	Culture* parent = NULL;
	Religion religion;
	SpeciesType species = NO_EXCLUSIVITY;
	uint8_t race = NO_EXCLUSIVITY;
	DrugType drug = DEF_DRUGTYPE;
	GenderBias genderBias = GENDERBIAS_NONE;
	Activity activity = NO_ACTIVITY;
	Caste caste = NO_CLASS_DISTINCTION;
	ToleranceLevel siblingCulture = TOLERANCE_VERY_HIGH;
	ToleranceLevel similarCulture = TOLERANCE_HIGH;
	ToleranceLevel awareCulture = TOLERANCE_MEDIUM;
	ToleranceLevel foreignCulture = TOLERANCE_MEDIUM;
	ToleranceLevel contradictingCulture = TOLERANCE_LOW;
	//high tolerance to dissidence will result in culture having chance to change alongside,
	//low tolerance result in increasing social isolation & zero they might attack you for it
	ToleranceLevel dissidence = TOLERANCE_MEDIUM;
	bool isSpeciesExclusive = false;
	bool isRaceExclusive = false;
	bool isCommunal = false;
	bool isFighter = false;
	bool isChildhood = false;
};

//TODO: function for analysing how similar two cultures are