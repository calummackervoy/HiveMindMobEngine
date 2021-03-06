#pragma once
#include "Engine.h"
#include "Menu.h"
#include "World.h"
#include "Character.h"
#include "Timer.h"

//Author: Calum Mackervoy
//Purpose: Manages the game as it runs

const double CAMERA_SPEED = 0.1;

enum GameMode : uint8_t {
    MENU,
    WORLD,
    REGION,
    BATTLE
};

//options for a Battle
struct BattleOptions {
    //TODO: other options
    bool lethal = true;
};

class Game {
public:
    Game(Engine* e, GameConfig config = {});
	~Game();

	//TODO: static GameConfig readGameConfig(string fileLocation);
	//TODO: methods for saving game data
	//TODO: methods for loading game data

	//method for running the game loop
	void run();

    //function to switch to Battle mode (passing options)
    void switchToBattle(BattleOptions options);
    //function to switch back
    void switchToRegion();

protected:
	Timer timer;
    Engine* e;
    World* world;
	Menu* activeMenu;
	Menu* activeMouseMenu;
	Map* map;
    GameMode mode;

	//method for initialising a new world
	void initWorld(GameConfig config = {});
	//method for loading the world from a saved game
	void loadWorld(std::string saveGame);

	//NOTE: temporary testing environment before worlds are being generated
	void setupTester();
};