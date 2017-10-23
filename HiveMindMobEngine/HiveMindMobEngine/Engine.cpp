#include "Engine.h"

Engine::Engine(string configFileLocation) {
	//run startup operations
	startup(configFileLocation);
}

Engine::~Engine() {
	shutdown();
}

void Engine::startup(string configFileLocation) {
	rm = new ResourceManager();
	file = new FileHandler();
	anim = new Animation(rm);
	audio = new Audio(rm);
	p = new Physics();
	r = new Renderer(rm);
	io = new InputHandler(r, file);

	//read in the configuration options
	readEngineConfig(configFileLocation);
}

DeviceResponse Engine::run() {
	r->drawScene();

	return io->respond();
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

void Engine::readEngineConfig(string configFileLocation) {
	setup = {};

	file->openStream(configFileLocation);

	//config files that define hat & clothing list locations
	setup.hatsLocation = file->getNextWord();
	setup.clothingLocation = file->getNextWord();

	file->closeStream();
}