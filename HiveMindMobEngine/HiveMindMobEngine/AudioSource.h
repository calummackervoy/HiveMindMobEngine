#pragma once
#include <SFML/Audio.hpp>
#include <string>

//Author: Calum Mackervoy
//Purpose: Holds and manages a sound buffer

using std::string;

class AudioSource {
public:
	//default sets them as -1
	AudioSource();
	~AudioSource();

	//load audio source from file
	void loadFromFile(int id, string fileLocation);
	//wipe the current audio source
	void clear();

	inline int getId() { return id; };
	//retrieve the stored clip
	inline sf::SoundBuffer* getClip() {
		if (id == -1) {
			throw std::exception("id was -1 (sound buffer has no value)");
		}
		return clip;
	};

private:
	int id;
	sf::SoundBuffer* clip;
};