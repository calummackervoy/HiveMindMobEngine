#pragma once
#include "Progress.h"

//Author: Calum Mackervoy
//Purpose: General class for tracking progress levels for different things

class ProgressTracker {
public:
	ProgressTracker();
	~ProgressTracker();

	//returns a copy of the progress
	inline Progress getItem(suint id);
	//inline void removeItem(suint id);
	inline int addItem(Progress &item);

	//activate a progress by id
	//if the prerequisites are not active it will return -1 (or if bounds erroneous)
	int activateProgress(suint id);
	void setPowerRating(suint id, ToleranceLevel newRating);
	void setCostRating(suint id, ToleranceLevel newRating);

protected:
	Progress* collection[MAX_PROGRESS];
};