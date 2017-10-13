#include "TileSprite.h"

TileSprite::TileSprite(bool useLighting, sf::Vector2f worldPos, int z) {
	this->worldpos = worldpos;;
	this->z = z;
	this->lighting = useLighting;
}

TileSprite::~TileSprite() {

}

void TileSprite::setWorldPosition(const sf::Vector2f &position) {
	worldpos = position;
	sf::Vector2f screenpos = worldToScreen(worldpos);
	screenpos.y -= z;
	setPosition(screenpos);
}

void TileSprite::setWorldZ(int z) {
	this->z = z;
	sf::Vector2f screenpos = worldToScreen(worldpos);
	screenpos.y -= z;
	setPosition(screenpos);
}