#pragma once
#include <string>
#include "Renderer.h"
#include "Physics.h"
#include "InputHandler.h"
#include "Animation.h"
#include "Profiling.h"
#include "Config.h"
#include "Audio.h"

using std::string;

//Author: Calum Mackervoy
//Purpose: Central class for managing the core-engine (renderer, physics etc)

class Engine {
public:
	Engine(string configFileLocation);
	~Engine();

	//accessing components externally
	inline ResourceManager* getRm() { return rm; };
	inline FileHandler* getFile() { return file; };
	inline Physics* getP() { return p; };
	inline InputHandler* getIo() { return io; };
	inline Renderer* getR() { return r; };
	//inline GameState* getState() { return state; };
	inline Animation* getAnim() { return anim; };
	EngineConfig getConfig() { return setup; };

	//run iteration of core game components' loop
	DeviceResponse run();
	//shutdown routine
	void shutdown();

private:
	ResourceManager* rm;
	FileHandler* file;
	Physics* p;
	InputHandler* io;
	Renderer* r;
	//GameState* state;
	Audio* audio;
	Animation* anim;
	Profiling profiler;
	EngineConfig setup;

	//startup routine
	void startup(string configFileLocation);

	//reading engine config options
	void readEngineConfig(string configFileLocation);
};