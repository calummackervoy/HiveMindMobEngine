#pragma once
#include "Config.h"
#include "Terrain.h"
#include <string>
#include <iostream>
#include <fstream>

//Author: Calum Mackervoy
//Purpose: provides functions for reading in various config files/savegames

using std::string;
using std::cout;
using std::ifstream;
using std::ios;

class FileHandler {
public:
	FileHandler();
	~FileHandler();

	//main configuration file
	static GameConfig readGameConfig(string fileLocation);
	//TODO: reading in different kinds of map or generic map config file?
	static Grid readMap(string mapLocation);
	//TODO: generic function for reading in a config file

	//methods for saving game data

	//methods for loading game data?

private:
};