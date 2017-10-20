#include "SceneManager.h"

SceneManager::SceneManager(ResourceManager* rm, Renderer* r, FileHandler* file,
		string hatsLocation, string clothingLocation) {
	this->rm = rm;
	focusIndex = 0;
	size = 0;

	//initialise a wardrobe
	//wardrobe = new Wardrobe(r, file, hatsLocation, clothingLocation);
	wardrobe = NULL;

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