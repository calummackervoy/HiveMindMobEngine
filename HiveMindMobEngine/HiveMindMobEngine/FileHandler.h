#pragma once
#include "Grid.h"
#include "Config.h"
#include "Terrain.h"
#include "Clothing.h"
#include <iostream>
#include <fstream>

//Author: Calum Mackervoy
//Purpose: provides functions for reading in various config files/savegames

using std::cout;
using std::ifstream;
using std::ios;
using std::map;

class FileHandler {
public:
	FileHandler();
	~FileHandler();

	//main configuration file
	//static GameConfig readGameConfig(string fileLocation);
	//TODO: reading in different kinds of map or generic map config file?
	static Grid* readMap(string mapLocation);

	//method for reading in bindings
	//reads config file for response codes & takes param for keys
	static void readBindings(map<DeviceKeyBinding, int> &bindings, string configLocation);

	//methods for saving game data

	//methods for loading game data?

	//method for reading in a Wardrobe config file
	static HatClothing** readWardrobe(string configLocation);

private:
};