#pragma once
#include "Organisation.h"
#include "Culture.h"
#include "Typedef.h"

const uint8_t MAX_GROUPSPP = 4;

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