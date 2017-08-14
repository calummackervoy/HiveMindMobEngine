#include "SceneManager.h"

SceneManager::SceneManager(ResourceManager* rm) {
	this->rm = rm;
	focusIndex = 0;
	size = 0;

	for (int i = 0; i < MAX_SCENE_ELEMS; i++) {
		scene[i] = NULL;
	}
}

SceneManager::~SceneManager() {
	delete[] scene;
	delete camera;
	camera = NULL;
	rm = NULL;
}

int SceneManager::addSpriteManager(SpriteManager* e) {
	for (int i = 0; i < MAX_SCENE_ELEMS; i++) {
		if (scene[i] == NULL) {
			scene[i] = e;
			e->setIndex(i);
			return i;
		}
	}
	return -1;
}

void SceneManager::removeSpriteManager(int i) {
	//bounds checking
	if (i < 0 || i >= MAX_SCENE_ELEMS) return;
	if (!scene[i]) return;

	delete scene[i];
	scene[i] = NULL;
}