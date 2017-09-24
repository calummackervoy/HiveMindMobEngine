#include "Device.h"

/*void Device::addBinding(sf::Event, ResponseCode) {

}

void Device::removeBinding(sf::Event) {

}

void Device::removeBindingAt(int i) {

}*/

void Device::readBindings(string configLocation) {
	//set this to the active stream
	file->openStream(configLocation, true);

	int temp;
	for (int i = 0; i <= (int)KEY_NULL; i++) {
		std::pair<DeviceKeyBinding, int> p;
		p.first = (MouseKeyboardKeys)i;
		temp = file->getNextInt();
		//being read in correctly then always converted to 0
		p.second = temp;
		cout << "BOUND " << (int)p.first << " TO " << p.second << std::endl;
		bindings.insert(p);
	}

	//close stream now we're done with it
	file->closeStream();
}