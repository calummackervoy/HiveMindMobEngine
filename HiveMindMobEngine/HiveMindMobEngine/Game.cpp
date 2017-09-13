#include "Game.h"

Game::Game(Engine* e, GameConfig config) {
    this->e = e;
    mode = MENU;

	//display the main menu screen
	MenuSetup setup;
	setup.title = "Hive Mind Mob Alpha";
	setup.optionLabels[0] = "Start New World";
	setup.optionActions[0] = MENU_WORLD_NEW;
	setup.optionLabels[1] = "Load World";
	setup.optionActions[1] = MENU_WORLD_LOAD;
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
			if (mode == MENU) {
				//find out which (if any) action selected and act accordingly
				switch (activeMenu->pollInput(r.clickPos)) {
				case MENU_ACTION_NONE:
					break;
				case MENU_WORLD_NEW:
					//TODO: take to the world setup screen
					cout << "new world being generated.." << std::endl;
					e->getR()->clearAll();
					mode = WORLD;
					break;
				case MENU_WORLD_LOAD:
					//TODO: take to the world load screen
					break;
				}
			}
			break;
		case DEVICE_ACT:
			
			break;
		case DEVICE_PAUSE:
			
			break;
        }
    }
}

void Game::initWorld(GameConfig config) {
	//TODO: init a world & load that map into renderer
	//world = new World(config.worldParams);
}

void Game::loadWorld(string saveGame) {

}

void Game::switchToBattle(BattleOptions options) {
	if(mode != REGION) return;
	mode = BATTLE;

	//TODO: clear non-combatants from screen, init the battle
}

void Game::switchToRegion() {
	if(mode != BATTLE) return;
	mode = REGION;
	
	//TODO: cleanup from the battle
}