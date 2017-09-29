#pragma once
#include "SpriteManager.h"
#include "AnimationManager.h"
#include "Emotion.h"
#include "Wardrobe.h"

//Author: Calum Mackervoy
//Purpose: Sprite-management for character sprites

//TODO: speech animation/indication

//defines the different animations available to a character
enum CharacterAnimations : uint8_t {
    WALK,
    JOG,
    RUN
};

class CharacterSpriteManager : public SpriteManager {
public:
    //TODO: meaningful default value for headCentre
    CharacterSpriteManager(ResourceManager* rm, Wardrobe* w, sf::Texture* tex,
		managerType type = MANAGER_CHARACTER, suint opaque = 100, suint depth = 0,
        sf::Vector2f headCentre = sf::Vector2f(50,50));
    ~CharacterSpriteManager();

    //overrides-- need override keyword here?
    void setPosition(sf::Vector2f pos);

    inline Emotion getExpression() {return expression;};
    inline Element* getHat() {return hat;};
    inline Element* getClothing() {return clothing;};

    inline void setExpression(Emotion val) {expression = val;};
    inline void setHat(Element* hat) {this->hat = hat;};
    inline void setClothing(Element* clothing) {this->clothing = clothing;};

protected:
    //co-ordinates used in positioning attachments
    sf::Vector2f bodyCentre;
    sf::Vector2f headCentre;

    Wardrobe* w;
    AnimationManager* am;
    Element* hat;
    Element* clothing;
    Emotion expression;
};