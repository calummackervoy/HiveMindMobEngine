#pragma once
#include "ResourceManager.h"

//Author: Calum Mackervoy
//Purpose: Manages audio assets and playback responsibilities

class Audio {
public:
    Audio(ResourceManager* rm);
    ~Audio();

    inline AudioSource* getAudioSourceAt(int i) {
		return rm->getAudioSource(i);
	}

	//change the background music from a file
	inline int setBackgroundMusic(string fileLocation) {
		if (!bgMusic->openFromFile(fileLocation)) return -1; // error
		else {
			//record that background music has been provided (to be played)
			backgroundMusicSet = true;
			return 0;
		}
	}

	//play the audio source specified
	inline void play(int id) {
		AudioSource* temp = rm->getAudioSource(id);
		if (id != currentId) {
			sound->setBuffer(*(temp->getClip()));
			currentId = id;
		}
		sound->play();
	}

	//function to start playing the background music stored
	inline void playBackgroundMusic() {
		if (!backgroundMusicSet) {
			std::cout << "attempt to play when background music not set" << std::endl;
		}
		bgMusic->play();
	}

	/*inline sf::Sound loadSound(int id) {
		sf::Sound sound = sf::Sound(sources[id]->getClip());
		return sound;
	}*/

	inline void setVolume(int volume) {
		if (volume < 0 || volume > 100) throw std::out_of_range("");
		sound->setVolume(volume);
	}

private:
    ResourceManager* rm;
    sf::Sound* sound; //for playing audio clips
	sf::Music* bgMusic; //for playing background music

    //efficiency: sounds can be played repeatedly until we play something else
	int currentId;
	bool backgroundMusicSet;
};