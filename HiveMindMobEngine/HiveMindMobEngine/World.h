#pragma once
#include "Save.h"
#include "Region.h"
#include "Technology.h"
#include "FileHandler.h"
#include "Config.h"
#include "MapWorld.h"

struct DateTime {
	suint year;
	uint8_t month;
	uint8_t day;
	uint8_t hour;
};

class World {
public:
	World(WorldParams params);
	//loading a world from save file
	World(WorldSave save);
	//procedurally generate a World?
	//World(int seed);
	~World();

	inline Tech* getTechAt(int i);
	inline int addTech(Tech* t);
	inline void removeTech(int i);

	//Date/Time getters and setters
	inline DateTime getDateTime() {return dateTime;};
	inline suint getYear() {return dateTime.year;};
	inline uint8_t getMonth() {return dateTime.month;};
	inline uint8_t getDay() {return dateTime.day;};
	inline uint8_t getHour() {return dateTime.hour;};
	inline void setDateTime(DateTime val) {dateTime = val;};
	inline void addYear() {	dateTime.year++; };
	inline void addMonth();
	inline void addDay();
	inline void addHour();

protected:
	Region* regions[MAX_REGIONS];
	Tech* techs[MAX_TECHS];
	MapWorld* map;
	DateTime dateTime;

	bool sanitiseWorldParams(WorldParams params);
	void generalisedWorldGen(WorldParams params);
};