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
using std::ofstream;
using std::ios;
using std::map;

class FileHandler {
public:
	//read defaults to true and source to empty
	FileHandler(std::string source = "", bool read = true);
	~FileHandler();

	//opens a stream for reading (if true) & writing if false
	void openStream(std::string source, bool read = true);
	//closes both streams
	void closeStream();

	//functions for reading specific values
	int getNextInt();
	std::string getNextWord();
	std::string getNextLine();

	//functions for writing specific values
	void write(std::string word);
	void writeLine(std::string line);

protected:
	ifstream* infile;
	ofstream* outfile;
};