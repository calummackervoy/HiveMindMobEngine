#include "Engine.h"

Engine::Engine(string configFileLocation) {
	//run startup operations
	startup(configFileLocation);
}

Engine::~Engine() {

}

void Engine::startup(string configFileLocation) {
	rm = new ResourceManager();
	anim = new Animation();
	audio = new Audio(rm);
	p = new Physics();
	r = new Renderer(rm);
	io = new InputHandler();

	//read in the configuration options
	//setup = FileHandler::readGameConfig(configFileLocation);
}

EngineResponse Engine::run() {
	r->drawScene();

	return{};
}

void Engine::shutdown() {
	delete p;
	delete io;
	delete r;
	//delete state;
	delete audio;
	delete anim;
	delete rm;
	delete this;
}