#pragma once
#include "Typedef.h"

//TODO: as yet unused?
//generalised function for searching an array for a given uint8_t
static bool searchArr(uint8_t key, uint8_t* arr, int size) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == key) return true;
	}
	return false;
}