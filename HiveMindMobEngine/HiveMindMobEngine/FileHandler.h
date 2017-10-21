#pragma once
#include "Config.h"
#include "Terrain.h"
#include "Clothing.h"
#include <iostream>
#include <fstream>
#include "Logger.h"

//Author: Calum Mackervoy
//Purpose: wrapper class for reading and writing operations

using std::cout;
using std::ifstream;
using std::ios;
using std::map;

class FileHandler {
public:
	//read defaults to true and source to empty
	FileHandler(string source = "", bool read = true);
	~FileHandler();

	//opens a stream for reading (if true) & writing if false
	void openStream(string source, bool read = true);
	//closes active stream
	void closeStream();

	//functions for reading specific values
	int getNextInt();
	string getNextWord();
	string getNextLine();

	//TODO: functions for writing specific values

protected:
	ifstream* file;
};