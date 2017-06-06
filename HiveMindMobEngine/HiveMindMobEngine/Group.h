#pragma once
#include "Organisation.h"
#include "Culture.h"
#include "Typedef.h"

enum GenerationMode : uint8_t {
	STABLE_POWER = 0,
	SEMISTABLE_POWER = 1,
	UNSTABLE_POWER = 2,
	CIVIL_WAR = 3,
	STATELESS = 4,
	ABSOLUTE_POWER = 5
};

//holds options for distribution of a region
struct GroupOptions {
	GroupType type = CULTURAL_GROUP;
};

struct GroupTypeBias {
	suint stateBias;
	suint politicalGroupBias;
	suint institutionBias;
	suint businessBias;
	suint gangBias;
	suint miscBias;
};

struct MemberBias {
	uint limit;
	suint highBias;
	suint mediumBias;
	suint lowBias;
};

struct GroupDist {
	GroupTypeBias groupTypeBias;
	MemberBias memberBias;
	GenerationMode mode;
	bool enableState = false;
};

class Group {
public:
	Group(GroupOptions options = {});
	//procedurally generate a group
	Group(uint seed, GroupDist dist = {});
	~Group();

protected:
	uint members;
	uint id;
	Culture culture;
	GroupType type;
	PowerClass powerClass;
	//groups should never be able to have no autonomy, only hives can have that
	AutonomyLevel autonomy;
};