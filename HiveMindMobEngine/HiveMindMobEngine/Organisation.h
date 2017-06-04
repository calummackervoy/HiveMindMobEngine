#pragma once

enum AutonomyLevel : byte {
	NO_AUTONOMY = 0,
	DEPOTISM = 1,
	HEIRARCHY = 2,
	DECENTRALISED = 3,
	ANARCHIST = 4
};

enum GroupType : byte {
	POLITICAL_GROUP = 0,
	STATE = 1,
	INSTITUTION = 2,
	BUSINESS = 3,
	GANG = 4,
	CULTURAL_GROUP = 5
};

enum PowerClass : byte {
	AUTHORITY_ALPHA = 0,
	AUTHORITY_CHALLENGER = 1,
	AUTHORTIY_RIGHTARM = 2,
	AUTHORITY_HIGH = 3,
	AUTHORITY_MEDIUM = 4,
	AUTHORITY_LOW = 5,
	AUTHORITY_VERYLOW = 6
};