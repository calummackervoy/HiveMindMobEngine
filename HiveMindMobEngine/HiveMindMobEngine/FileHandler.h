#pragma once
#include "Config.h"
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

private:
};