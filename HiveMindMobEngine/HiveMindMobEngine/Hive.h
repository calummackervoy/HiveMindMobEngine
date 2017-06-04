#pragma once
#include "Character.h"
#include "Organisation.h"

//NOTE: the game will probably be funnest if you can just keep growing
//so figure out how you're gonna start generating characters from seeds/hashes later
const int MAX_CHARACTERS = 64;

class Hive {
public:
	Hive(AutonomyLevel level = NO_AUTONOMY);
	~Hive();

private:
	Character members[MAX_CHARACTERS];
	AutonomyLevel level;
};