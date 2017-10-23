#include "GameSprite.h"

GameSprite::GameSprite(sf::Texture* tex, suint z, sf::Vector2f worldPos, GameSpriteType type) {
	this->worldpos = worldpos;
	this->z = z;
	this->id = MAX_ELEMS + 1; //default until ResourceManager accepts it
	this->type = type;
	setTexture(*tex);
}

GameSprite::~GameSprite() {

}

void GameSprite::setWorldPosition(float x, float y) {
	setWorldPosition(sf::Vector2f(x, y));
}

void GameSprite::setWorldPosition(const sf::Vector2f &position) {
	worldpos = position;
	sf::Vector2f screenpos = worldToScreen(worldpos);
	screenpos.y -= z;
	setPosition(screenpos);
}

void GameSprite::setWorldZ(int z) {
	this->z = z;
	sf::Vector2f screenpos = worldToScreen(worldpos);
	screenpos.y -= z * 0.866f;
	setPosition(screenpos);
}