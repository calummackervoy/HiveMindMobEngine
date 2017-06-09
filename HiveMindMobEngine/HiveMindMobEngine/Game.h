#pragma once
#include "Engine.h"
#include "World.h"

//Author: Calum Mackervoy
//Purpose: Manages the game as it runs

enum GameMode : uint8_t {
    MENU,
    WORLD,
    REGION,
    BATTLE
};

class Game {
public:
    Game(Engine* e, GameConfig config = {});
	~Game();

	//method for running the game loop
	void run();

protected:
    Engine* e;
    World* world;
    GameMode mode;
};