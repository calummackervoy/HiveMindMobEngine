#pragma once
#include <string>
#include "Renderer.h"

using std::string;

//Author: Calum Mackervoy
//Purpose: Central class for managing the core-engine (renderer, physics etc)

class Engine {
public:
	Engine(string configFileLocation);
	~Engine();


	//startup routine
	void startup(string configFileLocation);
	//run iteration of core game components' loop
	//Response run();
	//shutdown routine
	void shutdown();

private:
	Renderer* r;
};