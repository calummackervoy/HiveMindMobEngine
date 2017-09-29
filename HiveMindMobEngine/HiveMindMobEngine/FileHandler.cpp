#include "FileHandler.h"

FileHandler::FileHandler(string source, bool read) {
	//set the stream to NULL for now
	file = NULL;
	
	//initialise the source if necessary
	if (source != "") openStream(source, read);
}

FileHandler::~FileHandler() {
	closeStream();
}

void FileHandler::openStream(string source, bool read) {
	if (source == "") {
		cout << "READING KEY BINDINGS: configlocation was empty" << std::endl;
		return;
	}

	//close the stream to make sure it's free
	if (file != NULL) closeStream();

	//declare & open file in specified location with specified permissions
	if (read) file = new ifstream(source, ios::in);
	else file = new ifstream(source, ios::out);
}

void FileHandler::closeStream() {
	delete file;
	file = NULL;
}

int FileHandler::getNextInt() {
	if (file == NULL) {
		Logger::logError("FileHandler", "asked for int without opening stream.. 0 returned");
		return 0;
	}
	int temp;
	(*file) >> temp;
	return temp;
}

string FileHandler::getNextString() {
	if (file == NULL) {
		Logger::logError("FileHandler", "asked for string without opening stream.. '' returned");
		return "";
	}
	string temp;
	(*file) >> temp;
	return temp;
}