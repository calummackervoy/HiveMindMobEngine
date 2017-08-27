#pragma once
#include "Engine.h"
#include "Menu.h"
#include "World.h"

//Author: Calum Mackervoy
//Purpose: Manages the game as it runs

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

	//method for running the game loop
	void run();

    //function to switch to Battle mode (passing options)
    void switchToBattle(BattleOptions options);
    //function to switch back
    void switchToRegion();

protected:
    Engine* e;
    World* world;
	Menu* activeMenu;
    GameMode mode;

	//method for initialising a new world
	void initWorld(GameConfig config = {});
	//method for loading the world from a saved game
	void loadWorld(string saveGame);
};