#include "CharacterSpriteManager.h"

CharacterSpriteManager::CharacterSpriteManager(ResourceManager* rm, Wardrobe* w, sf::Sprite* model,
    sf::Texture* tex, managerType type, suint opaque, suint depth,
    sf::Vector2f headCentre) : SpriteManager(model, tex, type, opaque, depth) {
        expression = EMOTION_NEUTRAL;
        this->headCentre = headCentre;
        this->w = w;

        //select random hat/clothing
        //TODO: replace with more meaningful generation & don't just use default params
        bool hat = (bool)randInt(0,1);
        HatClothingPair temp = w->getRandom(hat);
        hat = temp.hat;
        clothing = temp.clothing;

        //bodyCentre half of the model size
        bodyCentre.x = ((sf::Sprite*)model)->getGlobalBounds().height * 0.5;
        bodyCentre.y = ((sf::Sprite*)model)->getGlobalBounds().width * 0.5;

        am = new AnimationManager(rm);
        //TODO: read animations from config file & add each to AM.. read all of class from config maybs?
}
CharacterSpriteManager::~CharacterSpriteManager() {
    delete am;
    delete hat;
    delete clothing;
}

void CharacterSpriteManager::setPosition(sf::Vector2f pos) {
    if(element != NULL && element->model != NULL) {
        ((sf::Sprite*)element->model)->setPosition(pos);

        if(clothing != NULL && clothing->model != NULL) {
			((sf::Sprite*)clothing->model)->setPosition(pos + bodyCentre);
        }

        if(hat != NULL && hat->model != NULL) {
			((sf::Sprite*)hat->model)->setPosition(pos + headCentre);
        }
    }
}