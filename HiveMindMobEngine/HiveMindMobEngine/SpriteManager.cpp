#include "SpriteManager.h"

SpriteManager::SpriteManager(sf::Sprite* model = NULL, sf::Texture* tex = NULL) {
	element = new Element;
	element->model = model;
	element->texture = tex;
	opaque = 100;
	depth = 0;
}

SpriteManager::~SpriteManager() {
	delete element->texture;
	delete element->model;
	delete element;
	element = NULL;
}