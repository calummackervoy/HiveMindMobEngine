#include <string>

using std::string;

//Author: Calum Mackervoy
//Purpose: Models a generated or random event

struct EventResponse {
	int id;
	string desc = "DEFAULT_RESPONSE";
	//TODO: function pointer to resulting action
};

struct Event {
	int id;
	string name = "DEFAULT_EVENT_NAME";
	string desc = "DEFAULT_EVENT_DESC";
	EventResponse responses[4];
};