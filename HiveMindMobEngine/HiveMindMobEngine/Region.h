#pragma once
#include <string>

using std::string;

const int MAX_GROUPS = 64;
const int MAX_COUNTRY_SIZE = 16;

struct Country {
	string name = "DEFAULT_COUNTRY";
	int numRegions = 2;
	int regionIds[MAX_COUNTRY_SIZE];
};

class Region {
public:
	Region(int id);
	//procedurally generate a region?
	//Region(int seed);
	~Region();

	inline int getId() {return id;};
	inline int getRegionAuthority() {return regionAuthority;};

	//generating region's groups and loading into focus
	void load();

protected:
	int id;
	int regionAuthority;
	bool inStruggle;
};