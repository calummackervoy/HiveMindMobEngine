#pragma once
#include <SFML\Graphics.hpp>

//Author: Calum Mackervoy
//Purpose: Stopwatch functionality

class Timer {
public:
	Timer() {
		//start the stop watch
		startTime = clock();
	}
	~Timer() {};

	//function to stop the watch
	inline void stop() { startTime = clock(); };

	//function to get how many seconds since you last set StartTime
	inline double getElapsed() {
		float now = clock();
		return double(clock() - startTime) / CLOCKS_PER_SEC;
	};

	//function to tell if a time has passed
	inline bool hasPassed(double time) {
		if (getElapsed() < time) return true;
		else return false;
	};

protected:
	//used to track the time elapsed
	clock_t startTime;
};