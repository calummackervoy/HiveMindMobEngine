#include "Audio.h"

Audio::Audio(ResourceManager* rm) {
	this->rm = rm;
	sound = new sf::Sound;
	bgMusic = new sf::Music;
	backgroundMusicSet = false;
	currentId = -1;
}

Audio::~Audio() {
	delete sound;
	delete bgMusic;
}
