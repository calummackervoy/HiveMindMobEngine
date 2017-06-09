#pragma once
#include <string>

using std::string;

struct WorldParams {
	string techConfig = "";
};

struct GameConfig {
    WorldParams worldParams;
};

enum EngineResponseCode : uint8_t {

};

struct EngineResponse {
    EngineResponseCode responseCode;
};