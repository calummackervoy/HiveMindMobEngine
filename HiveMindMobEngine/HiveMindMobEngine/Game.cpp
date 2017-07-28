#include "Game.h"

Game::Game(Engine* e, GameConfig config) {
    this->e = e;
    mode = MENU;

	//display the main menu screen
	MenuSetup setup;
	setup.title = "Hive Mind Mob Alpha";
	setup.options[0] = "Start New World";
	setup.options[1] = "Load World";
	setup.numOptions = 2;
	activeMenu = new Menu(e->getR(), e->getRm(), setup);
}

Game::~Game() {
    delete world;
}

void Game::run() {
    while(true) {
        //input response
        DeviceResponse r = e->run();

		switch(r.responseCode) {
		case DEVICE_RESPONSE_NONE:
			break;
		case DEVICE_SELECT:
			cout << "LEFT CLICK MADE! DEVICE SELECT" << std::endl;
			break;
		case DEVICE_ACT:
			cout << "RIGHT CLICK MADE! DEVICE ACT" << std::endl;
			break;
		case DEVICE_PAUSE:
			cout << "ESCAPE PRESSED! DEVICE PAUSE" << std::endl;
			break;
        }
    }
}

void Game::initWorld(GameConfig config) {
	world = new World(config.worldParams);
}

void Game::loadWorld(string saveGame) {

}