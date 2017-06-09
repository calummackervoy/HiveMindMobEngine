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
	static Map readMap(string mapLocation);
	static Tech** readTechConfig(string fileLocation);

	//methods for saving game data

	//methods for loading game data?

private:
};