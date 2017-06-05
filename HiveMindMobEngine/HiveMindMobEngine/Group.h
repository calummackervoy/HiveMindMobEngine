#pragma once
#include "Organisation.h"
#include "Culture.h"

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
	short stateBias;
	short politicalGroupBias;
	short institutionBias;
	short businessBias;
	short gangBias;
};

struct MemberBias {
	int limit;
	short highBias;
	short mediumBias;
	short lowBias;
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
	Group(int seed, GroupDist dist = {});
	~Group();

protected:
	int members;
	int id;
	Culture culture;
	GroupType type;
	PowerClass powerClass;
	AutonomyLevel autonomy;
};