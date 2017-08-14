#pragma once
#include <string>
#include <iostream>

//Author: Calum Mackervoy
//Purpose: convenience functions for different kinds of messages to the console
//TODO: add support for logging to file

using std::cout;
using std::endl;
using std::string;

class Logger {
public:
	inline static void logMessage(string message) {
		cout << message << endl;
	};
	inline static void logError(string source, string error) {
		cout << "[ERR-" << source << "] " << error << endl;
	}
	//overload passing an int to the error
	inline static void logError(string source, string error, string key, int val) {
		cout << "[ERR-" << source << "] " << error << " " << key << ": " << val << endl;
	}
};