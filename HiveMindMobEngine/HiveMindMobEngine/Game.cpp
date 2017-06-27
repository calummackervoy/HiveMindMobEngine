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
        EngineResponse r = e->run();

        switch(r.responseCode) {

        }
    }
}

void Game::initWorld(GameConfig config) {
	world = new World(config.worldParams);
}

void Game::loadWorld(string saveGame) {

}