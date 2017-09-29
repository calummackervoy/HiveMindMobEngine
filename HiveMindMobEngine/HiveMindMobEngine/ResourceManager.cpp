#include "ResourceManager.h"

ResourceManager::ResourceManager() {
	loadFonts();

	//initialise renderer's shiznaz to NULL to indicate free space
	scene = new Element*[MAX_ELEMS];
	hud = new Element*[MAX_ELEMS];
	for (int i = 0; i < MAX_ELEMS; i++) {
		scene[i] = NULL;
		hud[i] = NULL;
	}

	//init animators to NULL
	animations = new Animator*[MAX_ANIMATORS];
	for (int i = 0; i < MAX_ANIMATORS; ++i) {
		animations[i] = NULL;
	}
}

ResourceManager::~ResourceManager() {
	delete[] scene;
	delete[] hud;
	delete[] animations;

	for (int i = 0; i < NUM_FONTS; i++) {
		delete fonts[i];
	}
}

/*int ResourceManager::addHudElem(Element* e) {
	for (int i = 0; i < MAX_ELEMS; i++) {
		if (hud[i] == NULL) {
			hud[i] = e;
			e->index = i;
			return i;
		}
	}
	return -1;
}*/

/*void ResourceManager::removeHudElem(int i) {
	//bounds checking
	if (i < 0 || i > MAX_ELEMS) return;
	if (hud == NULL || hud[i] == NULL) return;

	delete hud[i]->model;
	hud[i]->model = NULL;
	delete hud[i]->texture;
	hud[i]->texture = NULL;
	delete hud[i];
	hud[i] = NULL;
}*/

void ResourceManager::clearScene() {
	for (int i = 0; i < MAX_ELEMS; i++) {
		if (!scene[i]) continue;
		delete scene[i]->model;
		scene[i]->model = NULL;
		//if (!scene[i]->skipTexDelete) {
			delete scene[i]->texture;
		//}
		scene[i]->texture = NULL;
		delete scene[i];
		scene[i] = NULL;
	}
}

void ResourceManager::clearHud() {
	for (int i = 0; i < MAX_ELEMS; i++) {
		if (!hud[i]) continue;
		delete hud[i]->model;
		hud[i]->model = NULL;
		//if (!scene[i]->skipTexDelete) {
		delete hud[i]->texture;
		//}
		hud[i]->texture = NULL;
		delete hud[i];
		hud[i] = NULL;
	}
}

int ResourceManager::addAudioSource(string fileLocation) {
	for (int i = 0; i < MAX_SOURCES; i++) {
		if (sources[i]->getId() == -1) {
			sources[i]->loadFromFile(i, fileLocation);
		}
		return i;
	}
	return -1;
}

void ResourceManager::removeAudioSource(int id) {
	if (id >= MAX_SOURCES || id < 0) {
		throw std::out_of_range("out of bounds for sources array");
	}
	sources[id]->clear();
}

void ResourceManager::loadFonts() {
	sf::Font* font = new sf::Font;
	//TODO: read in from config file
	if (!font->loadFromFile("../../assets/fonts/Abel-Regular.ttf")) {
		std::cout << "ERROR reading in fonts type!" << std::endl;
	}

	fonts[FONT_ABEL_REGULAR] = font;
}

int ResourceManager::addAnimator(Animator* resource) {
	//find an empty slot for the animator
	for (int i = 0; i < MAX_ANIMATORS; i++) {
		if (animations[i] == NULL) {
			//put it in this slot and store the location
			animations[i] = resource;
			resource->id = i;
			resource->startTime = clock();
			return i;
		}
	}
	return -1;
}

void ResourceManager::removeAnimator(uint id) {
	//bounds checking
	if(id >= MAX_ANIMATORS) return;
	
	//NOTE: AnimationManager will delete the animators
	animations[id] = NULL;
}