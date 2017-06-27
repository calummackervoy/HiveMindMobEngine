#include "AudioSource.h"

AudioSource::AudioSource() {
	id = -1; //index in the audioClips array
	clip = new sf::SoundBuffer;
}

void AudioSource::loadFromFile(int id, string fileLocation) {
	this->id = id;

	if (!clip->loadFromFile(fileLocation)) {
		throw std::exception("error reading file");
	}
}

void AudioSource::clear() {
	id = -1;
}

AudioSource::~AudioSource() {
	delete clip;
}