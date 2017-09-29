#pragma once
#include "Typedef.h"
#include "RendererConfig.h"
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

const int NUM_FONTS = 1;
const int MAX_SOURCES = 16;

class ResourceManager {
public:
	ResourceManager();
	~ResourceManager();

	inline Element* getSceneElem(int i) {
		//bounds checking
		if (i < 0 || i > MAX_ELEMS) throw std::exception("Index out of bounds");
		return scene[i];
	};
	inline int addSceneElem(Element* e) {
		for (int i = 0; i < MAX_ELEMS; i++) {
			if (scene[i] == NULL) {
				scene[i] = e;
				e->index = i;
				return i;
			}
		}
		return -1;
	};
	inline void removeSceneElem(int i) {
		//bounds checking
		if (i < 0 || i >= MAX_ELEMS) return;
		if (!scene[i]) return;

		delete scene[i]->model;
		scene[i]->model = NULL;
		delete scene[i]->texture;
		scene[i]->texture = NULL;
		delete scene[i];
		scene[i] = NULL;
	};

	inline Element* getHudElem(int i) {
		//bounds checking
		if (i < 0 || i > MAX_ELEMS) throw std::exception("Index out of bounds");
		return hud[i];
	}
	inline int addHudElem(Element* e) {
		for (int i = 0; i < MAX_ELEMS; i++) {
			if (hud[i] == NULL) {
				hud[i] = e;
				e->index = i;
				return i;
			}
		}
		return -1;
	};
	inline void removeHudElem(int i) {
		//bounds checking
		if (i < 0 || i > MAX_ELEMS) return;
		if (hud == NULL || hud[i] == NULL) return;

		delete hud[i]->model;
		hud[i]->model = NULL;
		delete hud[i]->texture;
		hud[i]->texture = NULL;
		delete hud[i];
		hud[i] = NULL;
	};

	void clearScene();
	void clearHud();

	//accessing/adding/removing audio sources from Audio's storage
	inline AudioSource* getAudioSource(int i) {
		if (i >= MAX_SOURCES || i < 0) {
			throw std::out_of_range("out of bounds for sources array");
		}
		return sources[i];
	}
	int addAudioSource(string fileLocation);
	void removeAudioSource(int id);

	//accessing/adding/removing animators from animation's storage
	inline Animator* getAnimator(uint i) {
		//bounds checking
		if (i > MAX_ANIMATORS) throw std::exception("Index out of bounds");
		return animations[i];
	};
	int addAnimator(Animator* resource);
	void removeAnimator(uint id);


	sf::Font* fonts[NUM_FONTS];

private:
	//initialisation: load all the fonts used in the game beforehand
	void loadFonts();

	//renderer's array of scene entities
	Element** scene;
	//renderer's array of HUD entities (the overlay)
	Element** hud;

	//Audio's storage of the different sound clips in use
	AudioSource** sources;

	//Animation's storage of the animators in the scene
	Animator** animations;
};