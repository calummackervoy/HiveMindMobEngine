#include "TileSprite.h"

TileSprite::TileSprite(bool useLighting, sf::Vector2i worldPos, int z) {
	this->worldpos = worldpos;;
	this->z = z;
	this->lighting = useLighting;
}

TileSprite::~TileSprite() {

}