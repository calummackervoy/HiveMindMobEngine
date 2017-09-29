#pragma once
#include <random>
#include "Logger.h"

//Author: Calum Mackervoy
//Purpose: random-value generation function

static suint randSuint(suint min, suint max, int seed = -1) {
	if (seed > 0) srand(seed);
	return (rand() % max) + min;
}

static int randInt(int min, int max, int seed = -1) {
	if (max == 0) max = 1;
	if (seed > 0) srand(seed);
	return (rand() % max) + min;
}

static float randFloat(float min, float max, int seed = -1) {
	if (max == 0.0f) max = 1.0f;
	if (seed > 0) srand(seed);
	return min + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (max - min)));
}
