#include "FileHandler.h"

FileHandler::FileHandler(string source, bool read) {
	//set the streams to NULL for now
	infile = NULL;
	outfile = NULL;
	
	//initialise a source if necessary
	if (source != "") openStream(source, read);
}

FileHandler::~FileHandler() {
	closeStream();
}

void FileHandler::openStream(string source, bool read) {
	if (source == "") {
		Logger::logError("FileHandler", "Attempt to open an empty source");
		return;
	}

	//close the stream to make sure it's free
	if (infile != NULL || outfile != NULL) closeStream();

	//declare & open file in specified location with specified permissions
	if (read) infile = new ifstream(source, ios::in);
	else outfile = new ofstream(source, ios::out);
}

void FileHandler::closeStream() {
	//streams will be closed by deconstructors
	delete infile;
	infile = NULL;
	delete outfile;
	outfile = NULL;
}

int FileHandler::getNextInt() {
	if (infile == NULL) {
		Logger::logError("FileHandler", "asked for int without opening stream.. 0 returned");
		return 0;
	}
	int temp;
	(*infile) >> temp;
	return temp;
}

string FileHandler::getNextWord() {
	if (infile == NULL) {
		Logger::logError("FileHandler", "asked for string without opening stream.. '' returned");
		return "";
	}
	string temp;
	(*infile) >> temp;
	return temp;
}

string FileHandler::getNextLine() {
	if (infile == NULL) {
		Logger::logError("FileHandler", "asked for string without opening stream.. '' returned");
		return "";
	}
	string temp;
	std::getline(*infile, temp);
	return temp;
}

void FileHandler::writeLine(string line) {
	if (outfile == NULL) {
		Logger::logError("FileHandler", "asked to write string without opening stream..");
		return;
	}
	*outfile << line << std::endl;
}