#pragma once
#include <string>
#include "Renderer.h"
#include "SceneManager.h"
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
	inline SceneManager* getScene() { return scene; };
	inline ResourceManager* getRm() { return rm; };
	inline Physics* getP() { return p; };
	inline InputHandler* getIo() { return io; };
	inline Renderer* getR() { return r; };
	//inline GameState* getState() { return state; };
	inline Animation* getAnim() { return anim; };
	GameConfig getConfig() { return setup; };

	//run iteration of core game components' loop
	DeviceResponse run();
	//shutdown routine
	void shutdown();

private:
	ResourceManager* rm;
	Physics* p;
	InputHandler* io;
	Renderer* r;
	SceneManager* scene;
	//GameState* state;
	Audio* audio;
	Animation* anim;
	Profiling profiler;
	GameConfig setup;

	//startup routine
	void startup(string configFileLocation);
};