#pragma once
#include "Terrain.h"
#include "GameSprite.h"
#include "AudioSource.h"
#include "Animator.h"
#include <SFML\Audio.hpp>
#include <iostream>

//author: Calum Mackervoy
//purpose: manages allocation for subsystems

//stores indicies in the fonts array
enum fontEnum : uint8_t {
	FONT_ABEL_REGULAR = 0
};

const suint NUM_FONTS = 1;
const suint MAX_SOURCES = 16;

class ResourceManager {
public:
	ResourceManager();
	~ResourceManager();

	inline sf::Drawable* getSceneElem(int i) {
		//bounds checking
		if (i < 0 || i > MAX_ELEMS) throw std::exception("Index out of bounds");
		return scene[i];
	};
	inline int addSceneElem(sf::Drawable* e) {
		for (int i = 0; i < MAX_ELEMS; i++) {
			if (scene[i] == NULL) {
				scene[i] = e;
				return i;
			}
		}
		return -1;
	};
	inline void removeSceneElem(int i) {
		//bounds checking
		if (i < 0 || i >= MAX_ELEMS) return;
		delete scene[i];
		scene[i] = NULL;
	};

	inline sf::Drawable* getHudElem(int i) {
		//bounds checking
		if (i < 0 || i > MAX_ELEMS) throw std::exception("Index out of bounds");
		return hud[i];
	}
	inline int addHudElem(sf::Drawable* e) {
		for (int i = 0; i < MAX_ELEMS; i++) {
			if (hud[i] == NULL) {
				hud[i] = e;
				return i;
			}
		}
		return -1;
	};
	inline void removeHudElem(int i) {
		//bounds checking
		if (i < 0 || i > MAX_ELEMS
				|| hud[i] == NULL) return;
		delete hud[i];
		hud[i] = NULL;
	};

	inline GameSprite* getSprite(int i) {
		//bounds checking
		if (i < 0 || i > MAX_ELEMS) throw std::exception("Index out of bounds");
		return sprites[i];
	};
	inline int addSprite(GameSprite* e) {
		for (int i = 0; i < MAX_ELEMS; i++) {
			if (sprites[i] == NULL) {
				sprites[i] = e;
				e->setIndex(i);
				return i;
			}
		}
		return -1;
	};
	inline void removeSprite(int i) {
		//bounds checking
		if (i < 0 || i >= MAX_ELEMS) return;
		if (!sprites[i]) return;

		delete sprites[i];
		sprites[i] = NULL;
	};

	void clearAll();
	void clearScene();
	void clearHud();
	void clearSprites();

	//accessing/adding/removing audio sources from Audio's storage
	inline AudioSource* getAudioSource(int i) {
		if (i >= MAX_SOURCES || i < 0) {
			throw std::out_of_range("out of bounds for sources array");
		}
		return sources[i];
	}
	int addAudioSource(std::string fileLocation);
	void removeAudioSource(int id);

	//accessing/adding/removing animators from animation's storage
	inline Animator* getAnimator(uint i) {
		//bounds checking
		if (i > MAX_ANIMATORS) throw std::exception("Index out of bounds");
		return animations[i];
	};
	int addAnimator(Animator* resource);
	void removeAnimator(uint id);

	//special storages
	sf::Font* fonts[NUM_FONTS]; //fonts
	sf::Texture* terrain[MAX_ACTIVE_TERRAINS];//terrain textures

private:
	//initialisation: load all the fonts used in the game beforehand
	void loadFonts();
	void loadTerrain();

	//renderer's array of scene entities
	sf::Drawable** scene;
	//renderer's array of HUD entities (the overlay)
	sf::Drawable** hud;

	GameSprite** sprites;

	//Audio's storage of the different sound clips in use
	AudioSource** sources;

	//Animation's storage of the animators in the scene
	Animator** animations;
};