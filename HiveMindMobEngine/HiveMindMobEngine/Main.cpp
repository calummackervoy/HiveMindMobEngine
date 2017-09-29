#include <SFML\Graphics.hpp>
#include "Engine.h"
#include "Game.h"

//Author: Calum Mackervoy
//Purpose: Entry point for the game

int main() {
	//set up the engine
	//passing the game's configuration file location
	Engine* e = new Engine("../../assets/config/engineConfig.txt");

	//set up the game
	Game g(e);

	//run the game
	g.run();

	return 0;
}