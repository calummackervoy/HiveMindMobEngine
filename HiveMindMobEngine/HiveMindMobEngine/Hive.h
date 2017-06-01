#pragma once

enum AutonomyLevel {
	NO_AUTONOMY = 0,
	DEPOTISM = 1,
	HEIRARCHY = 2,
	DECENTRALISED = 3,
	ANARCHIST = 4
};

class Hive {
public:
	Hive(AutonomyLevel level = NO_AUTONOMY);
	~Hive();

private:
	AutonomyLevel level;
};