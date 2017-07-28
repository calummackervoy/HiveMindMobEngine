#pragma once
#include <cstdint>

//Author: Calum Mackervoy
//Purpose: Models a scale used allover the place

enum ToleranceLevel : uint8_t {
	TOLERANCE_VERY_HIGH = 0,
	TOLERANCE_HIGH = 1,
	TOLERANCE_MEDIUM = 2,
	TOLERANCE_LOW = 3,
	TOLERANCE_VERY_LOW = 4,
	TOLERANCE_ZERO = 5
};