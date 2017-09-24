#include "Engine.h"

Engine::Engine(string configFileLocation) {
	//run startup operations
	startup(configFileLocation);
}

Engine::~Engine() {

}

void Engine::startup(string configFileLocation) {
	rm = new ResourceManager();
	file = new FileHandler();
	anim = new Animation(rm);
	audio = new Audio(rm);
	p = new Physics();
	r = new Renderer(rm);
	scene = new SceneManager(rm);
	io = new InputHandler(r, file);

	//read in the configuration options
	//setup = FileHandler::readGameConfig(configFileLocation);
}

DeviceResponse Engine::run() {
	r->drawScene();

	return io->respond();
}

void Engine::shutdown() {
	delete p;
	delete io;
	delete r;
	delete scene;
	//delete state;
	delete audio;
	delete anim;
	delete rm;
	delete this;
}