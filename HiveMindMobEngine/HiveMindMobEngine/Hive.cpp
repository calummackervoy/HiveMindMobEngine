#include "Hive.h"

Hive::Hive(AutonomyLevel level) {
	this->level = level;

	for (int i = 0; i < MAX_CHARACTERS; i++) {
		members[i] = NULL;
	}
}

Hive::~Hive() {

}