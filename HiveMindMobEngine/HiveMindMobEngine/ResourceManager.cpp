#include "ResourceManager.h"

ResourceManager::ResourceManager() {
	//initialise renderer's shiznaz to NULL to indicate free space
	scene = new Element*[MAX_ELEMS];
	hud = new Element*[MAX_ELEMS];
	for (int i = 0; i < MAX_ELEMS; i++) {
		scene[i] = NULL;
		hud[i] = NULL;
	}
}

ResourceManager::~ResourceManager() {
	delete[] scene;
	delete[] hud;
}

int ResourceManager::addSceneElem(Element* e) {
	for (int i = 0; i < MAX_ELEMS; i++) {
		if (scene[i] == NULL) {
			scene[i] = e;
			e->index = i;
			return i;
		}
	}
	return -1;
}

int ResourceManager::addHudElem(Element* e) {
	for (int i = 0; i < MAX_ELEMS; i++) {
		if (hud[i] == NULL) {
			hud[i] = e;
			e->index = i;
			return i;
		}
	}
	return -1;
}

void ResourceManager::removeSceneElem(int i) {
	//bounds checking
	if (i < 0 || i >= MAX_ELEMS) return;
	if (!scene[i]) return;

	delete scene[i]->model;
	scene[i]->model = NULL;
	delete scene[i]->texture;
	scene[i]->texture = NULL;
	delete scene[i];
	scene[i] = NULL;

}

void ResourceManager::removeHudElem(int i) {
	//bounds checking
	if (i < 0 || i > MAX_ELEMS) return;
	if (hud == NULL || hud[i] == NULL) return;

	delete hud[i]->model;
	hud[i]->model = NULL;
	delete hud[i]->texture;
	hud[i]->texture = NULL;
	delete hud[i];
	hud[i] = NULL;
}

void ResourceManager::clearScene() {
	for (int i = 0; i < MAX_ELEMS; i++) {
		if (!scene[i]) return;
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