#include "CharacterSpriteManager.h"

CharacterSpriteManager::CharacterSpriteManager(sf::Sprite* model, sf::Texture* tex, managerType type,
    suint opaque, suint depth) : SpriteManager(model, tex, type, opaque, depth) {
        am = new AnimationManager();
        expression = EMOTION_NEUTRAL;
        hat = NULL;
        clothing = NULL;
}
CharacterSpriteManager::~CharacterSpriteManager() {
    delete am;
    delete hat;
    delete clothing;
}

void CharacterSpriteManager::setPosition(sf::Vector2f pos) {

}