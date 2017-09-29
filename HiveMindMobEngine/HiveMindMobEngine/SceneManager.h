#pragma once
#include "Typedef.h"
#include "ResourceManager.h"
#include "CharacterSpriteManager.h"
#include "GeographySpriteManager.h"
#include "Camera.h"
#include "Logger.h"

//Author: Calum Mackervoy
//Purpose: Manages a scene of sprites, viewspace and camera

const int MAX_SCENE_ELEMS = 64;

//TODO: init when map generated
//TODO: checking, updating & tracking opacity

class SceneManager {
public:
	SceneManager(ResourceManager* rm, Renderer* r, FileHandler* file,
		string hatsLocation, string clothingLocation);
	~SceneManager();

	inline SpriteManager* getSpriteManager(int i) {
		//bounds checking
		if (i < 0 || i > MAX_SCENE_ELEMS) Logger::logError("SceneManager", "Index out of bounds getSpriteManager");
		return scene[i];
	};
	inline int addSpriteManager(SpriteManager* e) {
		for (int i = 0; i < MAX_SCENE_ELEMS; i++) {
			if (scene[i] == NULL) {
				scene[i] = e;
				e->setIndex(i);
				return i;
			}
		}
		return -1;
	}
	inline void removeSpriteManager(int i) {
		//bounds checking
		if (i < 0 || i >= MAX_SCENE_ELEMS) return;
		if (!scene[i]) return;

		delete scene[i];
		scene[i] = NULL;
	}

	Wardrobe* getWardrobe() { return wardrobe; };

protected:
	SpriteManager* scene[MAX_SCENE_ELEMS];
	ResourceManager* rm;
	Camera* camera; //TODO: for moving view of the map around
	Wardrobe* wardrobe;
	suint focusIndex;
	suint size;
};