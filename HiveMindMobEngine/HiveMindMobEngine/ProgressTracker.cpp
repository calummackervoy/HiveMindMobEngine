#include "ProgressTracker.h"

ProgressTracker::ProgressTracker() {
	//initialise all collection items to NULL
	for (int i = 0; i < MAX_PROGRESS; i++) {
		collection[i] = NULL;
	}
}

ProgressTracker::~ProgressTracker() {
	delete[] collection;
}

Progress ProgressTracker::getItem(suint id) {
	//bounds checking
	if (id < 0 || id > MAX_PROGRESS ||
		collection[id] == NULL) return{};

	Progress p = *collection[id];
	return p;
}

int ProgressTracker::addItem(Progress &item) {
	for (int i = 0; i < MAX_PROGRESS; i++) {
		if (collection[i] == NULL) {
			collection[i] = new Progress(item);
			collection[i]->id = i;
			return i;
		}
	}
	return -1;
}

int ProgressTracker::activateProgress(suint id) {
	//bounds checking
	if (id < 0 || id > MAX_PROGRESS ||
		collection[id] == NULL) return -1;

	//check pre-requisites are met
	for (int i = 0; i < PROGRESS_MAX_PRE_REQS; i++) {
		sint temp = collection[id]->prereqs[i];
		if (temp < 0 || temp > MAX_PROGRESS || collection[temp] == NULL) continue;
		if (!collection[temp]->active) return -1;
	}

	//otherwise good to go
	collection[id]->active = true;
	return 0;
}

void ProgressTracker::setPowerRating(suint id, ToleranceLevel newRating) {
	//bounds checking
	if (id < 0 || id > MAX_PROGRESS ||
		collection[id] == NULL) return;

	collection[id]->powerRating = newRating;
}

void ProgressTracker::setCostRating(suint id, ToleranceLevel newRating) {
	//bounds checking
	if (id < 0 || id > MAX_PROGRESS ||
		collection[id] == NULL) return;

	collection[id]->costRating = newRating;
}