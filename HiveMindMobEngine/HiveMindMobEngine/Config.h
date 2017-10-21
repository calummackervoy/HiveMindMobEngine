#pragma once
#include "Typedef.h"
#include "Organisation.h"
#include "Culture.h"
#include <string>
#include <map>
#include <SFML\Graphics.hpp>

using std::string;

//the maximum size of each axis (always square maps)
const uint MAX_MAP_SIZE = 20;

//parameters for the engine
struct EngineConfig {
	string hatsLocation;
	string clothingLocation;
};

enum WealthGrowth : uint8_t {
	DECLINE_RAPID,
	DECLINE_GRADUAL,
	DECLINE_SMOOTH,
	OSCILLATING_GROWTH,
	GROWTH_SMOOTH,
	GROWTH_GRADUAL,
	GROWTH_RAPID
};

//TODO: active map in game manager
enum MapType : uint8_t {
	MAP_WORLD,
	MAP_REGION,
	MAP_BATTLE
};

struct MapConfig {
	suint size = MAX_MAP_SIZE;
};

struct WorldParams {
	MapConfig mapGen = {};
	string techConfig = "";
	string map = "";
	suint numRegions = 32;
	GenerationMode worldPower = STABLE_POWER;
	WealthGrowth growth = OSCILLATING_GROWTH;
	ToleranceLevel povertyLevel = TOLERANCE_MEDIUM;
	GenderBias dominantGenderBias = GENDERBIAS_NONE;
	bool centralisedEmpire = false;
	bool generateMap = true;
};

struct GameConfig {
    WorldParams worldParams;
};

//IO response from a Device
//define the keys for mouse/keyboard
enum MouseKeyboardKeys : DeviceKeyBinding {
	CLICK_LEFT,
	CLICK_RIGHT,
	KEY_ESCAPE,
	KEY_UP,
	KEY_DOWN,
	KEY_LEFT,
	KEY_RIGHT,
	KEY_NULL //must be at the end -- for iterating over & assigning actions to keys
};

//NOTE: always add responses to the end or you'll have to change the key bindings config file
enum DeviceResponseCode {
	DEVICE_RESPONSE_NONE,
	DEVICE_SELECT,
	DEVICE_ACT,
	DEVICE_PAUSE,
	DEVICE_CAMERA_UP,
	DEVICE_CAMERA_DOWN,
	DEVICE_CAMERA_LEFT,
	DEVICE_CAMERA_RIGHT
};

struct DeviceResponse {
	DeviceResponseCode responseCode = DEVICE_RESPONSE_NONE;
	sf::Vector2i clickPos;
};