#include "SpriteManager.h"

SpriteManager::SpriteManager(sf::Sprite* model, sf::Texture* tex, managerType type,
	suint opaque, suint depth) {
	element = new Element;
	element->model = model;
	element->texture = tex;
	element->index = -1;
	this->type = type;
	this->opaque = opaque;
	this->depth = depth;
}

SpriteManager::~SpriteManager() {
	delete element->texture;
	delete element->model;
	delete element;
	element = NULL;
}