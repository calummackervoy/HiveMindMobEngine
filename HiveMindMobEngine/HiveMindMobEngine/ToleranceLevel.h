#pragma once
#include <cstdint>

//Author: Calum Mackervoy
//Purpose: Models a scale used allover the place

enum ToleranceLevel : uint8_t {
	//TOLERANCE_NULL,
	TOLERANCE_VERY_HIGH,
	TOLERANCE_HIGH,
	TOLERANCE_MEDIUM,
	TOLERANCE_LOW,
	TOLERANCE_VERY_LOW,
	TOLERANCE_ZERO,
};