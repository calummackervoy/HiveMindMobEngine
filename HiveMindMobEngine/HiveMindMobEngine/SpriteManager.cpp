#include "SpriteManager.h"

SpriteManager::SpriteManager(sf::Sprite* model, sf::Texture* tex, managerType type) {
	element = new Element;
	element->model = model;
	element->texture = tex;
	this->type = type;
	opaque = 100;
	depth = 0;
}

SpriteManager::~SpriteManager() {
	delete element->texture;
	delete element->model;
	delete element;
	element = NULL;
}