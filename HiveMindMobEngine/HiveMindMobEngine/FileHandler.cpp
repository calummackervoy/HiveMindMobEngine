#include "FileHandler.h"

FileHandler::FileHandler() {

}

FileHandler::~FileHandler() {

}

/*GameConfig FileHandler::readGameConfig(string fileLocation) {
	return{};
}*/

Grid* FileHandler::readMap(string mapLocation) {
	return{};
}

void FileHandler::readBindings(map<DeviceKeyBinding, int> &bindings,
	string configLocation) {

	if (configLocation == "") {
		cout << "READING KEY BINDINGS: configlocation was empty" << std::endl;
		return;
	}

	//declare & open file in specified location
	ifstream fp_in(configLocation, ios::in);

	int temp;
	for (int i = 0; i <= (int)KEY_NULL; i++) {
		std::pair<DeviceKeyBinding, int> p;
		p.first = (MouseKeyboardKeys)i;
		fp_in >> temp;
		//being read in correctly then always converted to 0
		p.second = temp;
		cout << "BOUND " << (int)p.first << " TO " << p.second << std::endl;
		bindings.insert(p);
	}

	fp_in.close();
}

HatClothing** FileHandler::readWardrobe(string configLocation) {
	//TODO: read in all hats/clothing from config file
}