#pragma once
#include <string>
#include "TypeDef.h"



enum DroneTypes : uint8_t {
	COPTER_RECON,
	SMALL_COPTER_TRANSPORT,
	MEDIUM_COPTER_TRANSPORT,
	LARGE_COPTER_TRANSPORT,
	INSECT_RECON,
	INSECT_COMBAT
};

//Player Characters have an AbilityDomain of their own
//AI Characters generate it out of categories of domain they belong to
struct AbilityDomain {
	uint8_t aiLevel = 0;
	uint8_t auditryPerception = 1;
	uint8_t brainComputingLevel = 0;
	uint8_t kineticPerception = 1;
	uint8_t shamanLevel = 0;
	uint8_t smellPerception = 1;
	DroneType droneCommand = 0;
	bool longRangeVision = false;
	bool nightVision = false;
	bool realtimeTranslation = false;
	bool telepathicCom = false;
};