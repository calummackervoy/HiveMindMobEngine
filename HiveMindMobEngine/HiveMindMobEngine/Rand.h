#pragma once
#include <random>
#include "Logger.h"

//Author: Calum Mackervoy
//Purpose: random-value generation function

static void seedRand(int seed) {
	if(seed > 0) srand(seed);
}

static suint randSuint(suint min, suint max) {
	if (max == 0) max = 1;
	max++;
	return (rand() % max) + min;
}

static int randInt(int min, int max) {
	if (max == 0) max = 1;
	max++;
	return (rand() % max) + min;
}

static float randFloat(float min, float max) {
	if (max == 0.0f) max = 1.0f;
	max++;
	return min + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (max - min)));
}
