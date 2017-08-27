#include "CharacterSpriteManager.h"

CharacterSpriteManager::CharacterSpriteManager(sf::Sprite* model, sf::Texture* tex, managerType type,
    suint opaque, suint depth, sf::Vector2f headCentre) : SpriteManager(model, tex, type, opaque, depth) {
        am = new AnimationManager();
        expression = EMOTION_NEUTRAL;
        hat = NULL;
        clothing = NULL;
        this->headCentre = headCentre;

        //bodyCentre half of the model size
        bodyCentre.x = model->getHeight() * 0.5;
        bodyCentre.y = model->getWidth() * 0.5;
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