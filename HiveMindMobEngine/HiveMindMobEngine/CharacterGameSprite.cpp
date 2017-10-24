#include "CharacterGameSprite.h"

CharacterGameSprite::CharacterGameSprite(sf::Texture* tex, suint z,
	sf::Vector2f worldPos) : GameSprite(tex, z, worldPos, GAMESPRITE_CHARACTER) {
	expression = EMOTION_NEUTRAL;

	hat = NULL;
	top = NULL;
	bottom = NULL;

	//select random hat/clothing
	//TODO: replace with more meaningful generation & don't just use default params
	//bool hat = (bool)randInt(0, 1);
	//HatClothingPair temp = w->getRandom(hat);
	//hat = temp.hat;
	//clothing = temp.clothing;
}

CharacterGameSprite::~CharacterGameSprite() {
	delete hat;
	delete top;
	delete bottom;
}

void CharacterGameSprite::setWorldPosition(float x, float y) {
	setWorldPosition(sf::Vector2f(x, y));
}
void CharacterGameSprite::setWorldPosition(const sf::Vector2f &position) {
	worldpos = position;
	sf::Vector2f screenpos = worldToScreen(worldpos);
	screenpos.y -= z;
	setPosition(screenpos);
}

void CharacterGameSprite::draw(sf::RenderWindow* win) {
	//set position of me
	sf::Vector2f pos = worldToScreen(worldpos);
	setPosition(pos);
	//set position of my clothes, ensure they're drawn in the same way as me..
	if (hat != NULL) {
		hat->setOrigin(this->getOrigin());
		hat->setPosition(pos);
	}
	if (top != NULL) {
		top->setOrigin(this->getOrigin());
		top->setPosition(pos);
	}
	if (bottom != NULL) {
		bottom->setOrigin(this->getOrigin());
		bottom->setPosition(pos);
	}

	//draw me
	win->draw(*this);
	//draw my clothes
	if (hat != NULL) win->draw(*hat);
	if (top != NULL) win->draw(*top);
	if (bottom != NULL) win->draw(*bottom);
}