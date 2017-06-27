#pragma once
#include <random>

//Author: Calum Mackervoy
//Purpose: random-value generation function

static int randInt(int min, int max) {
	return (rand() % max) + min;
}

static float randFloat(float min, float max) {
	return min + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (max - min)));
}
