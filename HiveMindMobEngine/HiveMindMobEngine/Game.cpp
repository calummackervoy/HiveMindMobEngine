#include "Game.h"

Game::Game(Engine* e, GameConfig config) {
    this->e = e;
    mode = MENU;
	activeMouseMenu = NULL;
	timer = Timer();

	//display the main menu screen
	MenuSetup setup;
	setup.title = "Hive Mind Mob Pre-Alpha";
	setup.optionLabels[0] = "Start New World";
	setup.optionActions[0] = MENU_WORLD_NEW;
	setup.optionLabels[1] = "Load World";
	setup.optionActions[1] = MENU_WORLD_LOAD;
	setup.numOptions = 2;
	activeMenu = new Menu(e->getR(), e->getRm(), setup);
	map = NULL;
}

Game::~Game() {
    delete world;
	delete map;
}

void Game::run() {
    while(true) {
        //input response
        DeviceResponse r = e->run();

		if (mode == WORLD && map != NULL) {
			//highlight tile being hovered over
			if (!r.click) map->highlightHover(e->getR()->getWindow(), r.clickPos);

			//draw map, then objects
			map->draw(e->getR()->getWindow());
		}

		//draw HUD over the top
		e->getR()->drawHud();

		switch (r.responseCode) {
		case DEVICE_RESPONSE_NONE:
			break;
		case DEVICE_SELECT:
			if (mode == MENU) {
				//find out which (if any) action selected and act accordingly
				switch (activeMenu->pollInput(r.clickPos)) {
				case MENU_ACTION_NONE:
					break;
				case MENU_WORLD_NEW:
					//TODO: navigate to the world setup screen instead
					//cout << "new world being generated.." << std::endl;
					e->getR()->clearAll();
					mode = WORLD;
					setupTester();
					break;
				case MENU_WORLD_LOAD:
					//TODO: take to the world load screen
					break;
				}
			}
			break;
		case DEVICE_ACT: {
			if (activeMouseMenu == NULL) {
				//TODO: check if a character has been selected!

				//create a mouse-level menu with available options
				MenuSetup commands;
				commands.optionLabels[0] = "Move here";
				commands.optionLabels[1] = "Example one";
				commands.optionLabels[2] = "Example two";
				commands.optionActions[0] = MENU_COMMAND_MOVE;
				commands.optionActions[1] = MENU_COMMAND_EXAMPLE_ONE;
				commands.optionActions[2] = MENU_COMMAND_EXAMPLE_TWO;
				commands.numOptions = 3;

				std::cout << "menu being created.." << std::endl;
				activeMouseMenu = new Menu(e->getR(), e->getRm(), commands, MENU_MOUSE);
				//delete activeMouseMenu;
			}
			break;
		}
		case DEVICE_PAUSE:
			break;
		case DEVICE_CAMERA_UP:
			//ensure camera does not move too fast
			if (timer.hasPassed(CAMERA_SPEED)) {
				//subtract on the X axis to head north-west
				map->moveViewCentre(-1, 0);
				timer.stop();
			}
			break;
		case DEVICE_CAMERA_DOWN:
			//ensure camera does not move too fast
			if (timer.hasPassed(CAMERA_SPEED)) {
				//add on the X axis to head south-east
				map->moveViewCentre(1, 0);
				timer.stop();
			}
			break;
		case DEVICE_CAMERA_LEFT:
			//ensure camera does not move too fast
			if (timer.hasPassed(CAMERA_SPEED)) {
				//add on the Y axis to head south-west
				map->moveViewCentre(0, 1);
				timer.stop();
			}
			break;
		case DEVICE_CAMERA_RIGHT:
			//ensure camera does not move too fast
			if (timer.hasPassed(CAMERA_SPEED)) {
				//subtract on the Y axis to head north-east
				map->moveViewCentre(0, -1);
				timer.stop();
			}
			break;
        }
    }
}

void Game::setupTester() {
	//setup the map
	map = new Map(e->getR(), e->getRm(), 20);
	//TODO: read from a config or setup menu
	map->readMap(e->getFile(), "../../assets/config/map1.txt");
	//Region* region = new Region(e->getRm(), 0);

	//read test character from config file
	Character* c = new Character(e->getR(), e->getRm(), e->getFile(), "../../assets/config/character/testcharacter.txt");
	//c->save("../../assets/config/character/testsave.txt");

	//set character tile position & place sprite here
	//TODO: set this position according to a tile position in the map
	map->insertSprite(0,0,e->getRm(), c->getSprite(), SPRITETYPE_OCCUPANT);
	//c->getSpriteManager()->setPosition(sf::Vector2f(500,500));

	//TODO: add a randomly generated character to the scene

	//TODO: moving the char move to clickpos
	//TODO: char switch between sprites depending on direction moving
	//TODO: randomly generate another character alongside
}

void Game::initWorld(GameConfig config) {
	//TODO: init a world & load that map into renderer
	//world = new World(config.worldParams);

	//NOTE: temporary world initialisation for testing

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