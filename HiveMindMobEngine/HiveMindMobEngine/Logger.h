#pragma once
#include <iostream>

//Author: Calum Mackervoy
//Purpose: convenience functions for different kinds of messages to the console
//TODO: add support for logging to file

using std::cout;
using std::endl;

class Logger {
public:
	inline static void logMessage(std::string message) {
		cout << message << endl;
	};
	inline static void logError(std::string source, std::string error) {
		cout << "[ERR-" << source << "] " << error << endl;
	}
	//overload passing an int to the error
	inline static void logError(std::string source, std::string error, std::string key, int val) {
		cout << "[ERR-" << source << "] " << error << " " << key << ": " << val << endl;
	}
};