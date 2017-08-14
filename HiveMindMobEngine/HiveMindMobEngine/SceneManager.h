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

class SceneManager {
public:
	SceneManager(ResourceManager* rm);
	~SceneManager();

	inline SpriteManager* getSpriteManager(int i) {
		//bounds checking
		if (i < 0 || i > MAX_SCENE_ELEMS) Logger::logError("SceneManager", "Index out of bounds getSpriteManager");
		return scene[i];
	};
	inline int addSpriteManager(SpriteManager* e);
	inline void removeSpriteManager(int i);

protected:
	SpriteManager* scene[MAX_SCENE_ELEMS];
	ResourceManager* rm;
	Camera* camera;
	suint focusIndex;
	suint size;
};