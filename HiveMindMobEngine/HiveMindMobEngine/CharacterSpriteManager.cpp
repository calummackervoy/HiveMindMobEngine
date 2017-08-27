#include "CharacterSpriteManager.h"

CharacterSpriteManager::CharacterSpriteManager(ResourceManager* rm, sf::Sprite* model, sf::Texture* tex, managerType type,
    suint opaque, suint depth, sf::Vector2f headCentre) : SpriteManager(model, tex, type, opaque, depth) {
        expression = EMOTION_NEUTRAL;
        hat = NULL;
        clothing = NULL;
        this->headCentre = headCentre;

        //bodyCentre half of the model size
        bodyCentre.x = model->getHeight() * 0.5;
        bodyCentre.y = model->getWidth() * 0.5;

        am = new AnimationManager(rm);
        //TODO: read animations from config file & add each to AM.. read all of class from config maybs?
}
CharacterSpriteManager::~CharacterSpriteManager() {
    delete am;
    delete hat;
    delete clothing;
}

void CharacterSpriteManager::setPosition(sf::Vector2f pos) {
    if(element !== NULL && element->model !== NULL) {
        element->model->setPosition(pos);
        if(clothing !== NULL && clothing->model !== NULL) {
            clothing->model->setPosition(pos + bodyCentre);
        }
        if(hat !== NULL && hat->model !== NULL) {
            hat->model->setPosition(pos + headCentre);
        }
    }
}