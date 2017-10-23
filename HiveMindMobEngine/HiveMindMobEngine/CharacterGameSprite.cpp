#include "CharacterGameSprite.h"

CharacterGameSprite::CharacterGameSprite(sf::Texture* tex, suint z,
	sf::Vector2f worldPos) : GameSprite(tex, z, worldPos, GAMESPRITE_CHARACTER) {
	expression = EMOTION_NEUTRAL;

	//bodyCentre half of the model size

	//select random hat/clothing
	//TODO: replace with more meaningful generation & don't just use default params
	//bool hat = (bool)randInt(0, 1);
	//HatClothingPair temp = w->getRandom(hat);
	//hat = temp.hat;
	//clothing = temp.clothing;
}

CharacterGameSprite::~CharacterGameSprite() {

}

void CharacterGameSprite::setWorldPosition(float x, float y) {
	setWorldPosition(sf::Vector2f(x, y));
}
void CharacterGameSprite::setWorldPosition(const sf::Vector2f &position) {
	worldpos = position;
	sf::Vector2f screenpos = worldToScreen(worldpos);
	screenpos.y -= z;
	setPosition(screenpos);
	/*
	if(element != NULL && element->model != NULL) {
	((sf::Sprite*)element->model)->setPosition(pos);

	if(clothing != NULL && clothing->model != NULL) {
	((sf::Sprite*)clothing->model)->setPosition(pos + bodyCentre);
	}

	if(hat != NULL && hat->model != NULL) {
	((sf::Sprite*)hat->model)->setPosition(pos + headCentre);
	}
	}
	*/
}